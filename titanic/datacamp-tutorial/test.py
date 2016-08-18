# Import the Pandas library
import pandas as pd

# Load the train and test datasets to create two DataFrames
train_url = "http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/train.csv"
train = pd.read_csv(train_url)

test_url = "http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/test.csv"
test = pd.read_csv(test_url)

def view_data():
    #Print the `head` of the train and test dataframes
    # print(train.head())
    # print(test.head())

    # print(train.describe())
    # print(train.shape)

    # Passengers that survived vs passengers that passed away
    print(train["Survived"].value_counts())

    # As proportions
    print(train["Survived"].value_counts(normalize = True))

    # Males that survived vs males that passed away
    print(train["Survived"][train["Sex"] == 'male'].value_counts())

    # Females that survived vs Females that passed away
    print(train["Survived"][train["Sex"] == 'female'].value_counts())

    # Normalized male survival
    print(train["Survived"][train["Sex"] == 'male'].value_counts(normalize = True))

    # Normalized female survival
    print(train["Survived"][train["Sex"] == 'female'].value_counts(normalize = True))

def chapter1():
    train["Child"] = float('NaN')
    # train.loc[train["Age"] < 18, "Child"] = 1
    # train.loc[train["Age"] >= 18, "Child"] = 0

    train.loc[train["Age"] < 18, "Child"] = 1
    train.loc[train["Age"] >= 18, "Child"] = 0

    # Print normalized Survival Rates for passengers under 18
    print(train["Survived"][train["Child"] == 1].value_counts(normalize = True))

    # Print normalized Survival Rates for passengers 18 or older
    print(train["Survived"][train["Child"] == 0].value_counts(normalize = True))

    test_one = test
    test_one["Survived"] = 0

    test_one.loc[test_one["Sex"] == "female", "Survived"] = 1

    print(test_one["Survived"])

def chapter2():
    import numpy

    # Import 'tree' from scikit-learn library
    from sklearn import tree

    # Convert the male and female groups to integer form
    # train["Sex"][train["Sex"] == "male"] = 0

    train.loc[train["Sex"] == "male", "Sex"] = 0

    # Impute the Embarked variable
    # train["Embarked"] =

    # Convert the Embarked classes to integer form
    # train["Embarked"][train["Embarked"] == "S"] = 0

    # Print the Sex and Embarked columns

# chapter1()
chapter2()
