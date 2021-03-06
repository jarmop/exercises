import pandas
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.cross_validation import KFold
from sklearn.linear_model import LogisticRegression
from sklearn import cross_validation
from sklearn.ensemble import RandomForestClassifier
import re
import operator
from sklearn.feature_selection import SelectKBest, f_classif
import matplotlib.pyplot as plt
from sklearn.ensemble import GradientBoostingClassifier

# A dictionary mapping family name to id
family_id_mapping = {}

def clean_up(titanic):
    # Print the first row of the dataframe.
    # print(titanic.head(1))

    # print(titanic.describe())

    titanic["Age"] = titanic["Age"].fillna(titanic["Age"].median())

    # Find all the unique genders -- the column appears to contain only male and female.
    # print(titanic["Sex"].unique())

    # Replace all the occurences of male with the number 0.
    titanic.loc[titanic["Sex"] == "male", "Sex"] = 0
    titanic.loc[titanic["Sex"] == "female", "Sex"] = 1

    # print(titanic["Embarked"].unique())

    titanic["Embarked"] = titanic["Embarked"].fillna('S')

    titanic.loc[titanic["Embarked"] == "S", "Embarked"] = 0
    titanic.loc[titanic["Embarked"] == "C", "Embarked"] = 1
    titanic.loc[titanic["Embarked"] == "Q", "Embarked"] = 2

def clean_up_test(titanic_test):
    titanic_test["Age"] = titanic_test["Age"].fillna(titanic["Age"].median())

    # Replace all the occurences of male with the number 0.
    titanic_test.loc[titanic_test["Sex"] == "male", "Sex"] = 0
    titanic_test.loc[titanic_test["Sex"] == "female", "Sex"] = 1

    titanic_test["Embarked"] = titanic_test["Embarked"].fillna('S')

    titanic_test.loc[titanic_test["Embarked"] == "S", "Embarked"] = 0
    titanic_test.loc[titanic_test["Embarked"] == "C", "Embarked"] = 1
    titanic_test.loc[titanic_test["Embarked"] == "Q", "Embarked"] = 2

    titanic_test["Fare"] = titanic_test["Fare"].fillna(titanic_test["Fare"].median())

# A function to get the title from a name.
def get_title(name):
    # Use a regular expression to search for a title.  Titles always consist of capital and lowercase letters, and end with a period.
    title_search = re.search(' ([A-Za-z]+)\.', name)
    # If the title exists, extract and return it.
    if title_search:
        return title_search.group(1)
    return ""

def add_title(titanic):
    # Get all the titles and print how often each one occurs.
    titles = titanic["Name"].apply(get_title)
    # print(pandas.value_counts(titles))

    # Map each title to an integer.  Some titles are very rare, and are compressed into the same codes as other titles.
    title_mapping = {"Mr": 1, "Miss": 2, "Mrs": 3, "Master": 4, "Dr": 5, "Rev": 6, "Major": 7, "Col": 7, "Mlle": 8,
                     "Mme": 8, "Don": 9, "Lady": 10, "Countess": 10, "Jonkheer": 10, "Sir": 9, "Capt": 7, "Ms": 2}
    for k, v in title_mapping.items():
        titles[titles == k] = v

    # Verify that we converted everything.
    # print(pandas.value_counts(titles))

    # Add in the title column.
    titanic["Title"] = titles

def add_title_test(titanic):
    # Get all the titles and print how often each one occurs.
    titles = titanic["Name"].apply(get_title)
    # print(pandas.value_counts(titles))

    # Map each title to an integer.  Some titles are very rare, and are compressed into the same codes as other titles.
    title_mapping = {"Mr": 1, "Miss": 2, "Mrs": 3, "Master": 4, "Dr": 5, "Rev": 6, "Major": 7, "Col": 7, "Mlle": 8,
                     "Mme": 8, "Don": 9, "Lady": 10, "Countess": 10, "Jonkheer": 10, "Sir": 9, "Capt": 7, "Ms": 2, "Dona": 10}
    for k, v in title_mapping.items():
        titles[titles == k] = v

    # Verify that we converted everything.
    # print(pandas.value_counts(titles))

    # Add in the title column.
    titanic["Title"] = titles

# A function to get the id given a row
def get_family_id(row):
    # Find the last name by splitting on a comma
    last_name = row["Name"].split(",")[0]
    # Create the family id
    family_id = "{0}{1}".format(last_name, row["FamilySize"])
    # Look up the id in the mapping
    if family_id not in family_id_mapping:
        if len(family_id_mapping) == 0:
            current_id = 1
        else:
            # Get the maximum id from the mapping and add one to it if we don't have an id
            current_id = (max(family_id_mapping.items(), key=operator.itemgetter(1))[1] + 1)
        family_id_mapping[family_id] = current_id
    return family_id_mapping[family_id]

def add_family_id(titanic):
    # Get the family ids with the apply method
    family_ids = titanic.apply(get_family_id, axis=1)

    # There are a lot of family ids, so we'll compress all of the families under 3 members into one code.
    family_ids[titanic["FamilySize"] < 3] = -1

    # Print the count of each unique id.
    # print(pandas.value_counts(family_ids))

    titanic["FamilyId"] = family_ids

def add_features(titanic):
    # Generating a familysize column
    titanic["FamilySize"] = titanic["SibSp"] + titanic["Parch"]

    # The .apply method generates a new series
    titanic["NameLength"] = titanic["Name"].apply(lambda x: len(x))

    add_title(titanic)

    add_family_id(titanic)

def add_features_test(titanic):
    # Generating a familysize column
    titanic["FamilySize"] = titanic["SibSp"] + titanic["Parch"]

    # The .apply method generates a new series
    titanic["NameLength"] = titanic["Name"].apply(lambda x: len(x))

    add_title_test(titanic)

    add_family_id(titanic)

def show_best_predictors(titanic):
    predictors = ["Pclass", "Sex", "Age", "SibSp", "Parch", "Fare", "Embarked", "FamilySize", "Title", "FamilyId"]

    # Perform feature selection
    selector = SelectKBest(f_classif, k=5)
    selector.fit(titanic[predictors], titanic["Survived"])

    # Get the raw p-values for each feature, and transform from p-values into scores
    scores = -np.log10(selector.pvalues_)

    # Plot the scores.  See how "Pclass", "Sex", "Title", and "Fare" are the best?
    plt.bar(range(len(predictors)), scores)
    plt.xticks(range(len(predictors)), predictors, rotation='vertical')
    plt.show()

def linear_regression():
    # The columns we'll use to predict the target
    predictors = ["Pclass", "Sex", "Age", "SibSp", "Parch", "Fare", "Embarked"]

    # Initialize our algorithm class
    alg = LinearRegression()
    # Generate cross validation folds for the titanic dataset.  It returns the row indices corresponding to train and test.
    # We set random_state to ensure we get the same splits every time we run this.
    kf = KFold(titanic.shape[0], n_folds=3, random_state=1)

    predictions = []
    for train, test in kf:
        # The predictors we're using to train the algorithm.  Note how we only take the rows in the train folds.
        train_predictors = (titanic[predictors].iloc[train,:])
        # The target we're using to train the algorithm.
        train_target = titanic["Survived"].iloc[train]
        # Training the algorithm using the predictors and target.
        alg.fit(train_predictors, train_target)
        # We can now make predictions on the test fold
        test_predictions = alg.predict(titanic[predictors].iloc[test,:])
        predictions.append(test_predictions)

    # print(predictions)
    # print(titanic["Survived"])

    # The predictions are in three separate numpy arrays.  Concatenate them into one.
    predictions = np.concatenate(predictions)

    # print(predictions)

    # Map predictions to outcomes (only possible outcomes are 1 and 0)
    predictions[predictions > .5] = 1
    predictions[predictions <=.5] = 0

    # print(predictions)
    # print(titanic['Survived'])

    # correctPredictions = 0
    # i = 0
    # for survived in titanic['Survived']:
    #     if survived == predictions[i]:
    #         correctPredictions += 1
    #     i += 1
    #
    # accuracy = correctPredictions / len(predictions)

    print(predictions == titanic["Survived"])

    accuracy = sum(predictions[predictions == titanic["Survived"]]) / len(predictions)

    print(accuracy)

def logistic_regression():
    predictors = ["Pclass", "Sex", "Age", "SibSp", "Parch", "Fare", "Embarked"]

    # Initialize our algorithm
    alg = LogisticRegression(random_state=1)
    # Compute the accuracy score for all the cross validation folds.  (much simpler than what we did before!)
    scores = cross_validation.cross_val_score(alg, titanic[predictors], titanic["Survived"], cv=3)
    # Take the mean of the scores (because we have one for each fold)
    print(scores.mean())

def random_forest():
    # predictors = ["Pclass", "Sex", "Age", "SibSp", "Parch", "Fare", "Embarked"]
    # Pick only the four best features.
    predictors = ["Pclass", "Sex", "Fare", "Title"]

    # Initialize our algorithm with the default paramters
    # n_estimators is the number of trees we want to make
    # min_samples_split is the minimum number of rows we need to make a split
    # min_samples_leaf is the minimum number of samples we can have at the place where a tree branch ends (the bottom points of the tree)
    alg = RandomForestClassifier(random_state=1, n_estimators=150, min_samples_split=4, min_samples_leaf=2)

    scores = cross_validation.cross_val_score(alg, titanic[predictors], titanic["Survived"], cv=3)
    # Take the mean of the scores (because we have one for each fold)
    print(scores.mean())

def ensembling():
    # The algorithms we want to ensemble.
    # We're using the more linear predictors for the logistic regression, and everything with the gradient boosting classifier.
    algorithms = [
        [GradientBoostingClassifier(random_state=1, n_estimators=25, max_depth=3),
         ["Pclass", "Sex", "Age", "Fare", "Embarked", "FamilySize", "Title", "FamilyId"]],
        [LogisticRegression(random_state=1),
         ["Pclass", "Sex", "Fare", "FamilySize", "Title", "Age", "Embarked"]]
    ]

    # Initialize the cross validation folds
    kf = KFold(titanic.shape[0], n_folds=3, random_state=1)

    predictions = []
    for train, test in kf:
        train_target = titanic["Survived"].iloc[train]
        full_test_predictions = []
        # Make predictions for each algorithm on each fold
        for alg, predictors in algorithms:
            # Fit the algorithm on the training data.
            alg.fit(titanic[predictors].iloc[train, :], train_target)
            # Select and predict on the test fold.
            # The .astype(float) is necessary to convert the dataframe to all floats and avoid an sklearn error.
            test_predictions = alg.predict_proba(titanic[predictors].iloc[test, :].astype(float))[:, 1]
            full_test_predictions.append(test_predictions)
        # Use a simple ensembling scheme -- just average the predictions to get the final classification.
        test_predictions = (full_test_predictions[0] + full_test_predictions[1]) / 2
        # Any value over .5 is assumed to be a 1 prediction, and below .5 is a 0 prediction.
        test_predictions[test_predictions <= .5] = 0
        test_predictions[test_predictions > .5] = 1
        predictions.append(test_predictions)

    # Put all the predictions together into one array.
    predictions = np.concatenate(predictions, axis=0)

    # Compute accuracy by comparing to the training data.
    accuracy = sum(predictions[predictions == titanic["Survived"]]) / len(predictions)
    print(accuracy)

def create_submission():
    predictors = ["Pclass", "Sex", "Age", "Fare", "Embarked", "FamilySize", "Title", "FamilyId"]

    algorithms = [
        [GradientBoostingClassifier(random_state=1, n_estimators=25, max_depth=3), predictors],
        [LogisticRegression(random_state=1), ["Pclass", "Sex", "Fare", "FamilySize", "Title", "Age", "Embarked"]]
    ]

    full_predictions = []
    for alg, predictors in algorithms:
        # Fit the algorithm using the full training data.
        alg.fit(titanic[predictors], titanic["Survived"])
        # Predict using the test dataset.  We have to convert all the columns to floats to avoid an error.
        predictions = alg.predict_proba(titanic_test[predictors].astype(float))[:, 1]
        full_predictions.append(predictions)

    # The gradient boosting classifier generates better predictions, so we weight it higher.
    predictions = (full_predictions[0] * 3 + full_predictions[1]) / 4

    # print(predictions)

    predictions[predictions <= .5] = 0
    predictions[predictions > .5] = 1
    predictions = predictions.astype(int)

    # print(predictions)

    submission = pandas.DataFrame({
        "PassengerId": titanic_test["PassengerId"],
        "Survived": predictions
    })

    submission.to_csv("kaggle.csv", index=False)

# We can use the pandas library in python to read in the csv file.
# This creates a pandas dataframe and assigns it to the titanic variable.
titanic = pandas.read_csv("../data/train.csv")
titanic_test = pandas.read_csv("../data/test.csv")

clean_up(titanic)
add_features(titanic)
clean_up_test(titanic_test)
add_features_test(titanic_test)

# show_best_predictors(titanic)
# linear_regression()
# logistic_regression()
# random_forest()
# ensembling()

create_submission()

# predictors = ["Pclass", "Sex", "Age", "SibSp", "Parch", "Fare", "Embarked"]
#
# # Initialize the algorithm class
# alg = LogisticRegression(random_state=1)
#
# # Train the algorithm using all the training data
# alg.fit(titanic[predictors], titanic["Survived"])
#
# # Make predictions using the test set.
# predictions = alg.predict(titanic_test[predictors])
#
# # Create a new dataframe with only the columns Kaggle wants from the dataset.
# submission = pandas.DataFrame({
#     "PassengerId": titanic_test["PassengerId"],
#     "Survived": predictions
# })
#
# # print(submission)
# submission.to_csv("kaggle.csv", index=False)
