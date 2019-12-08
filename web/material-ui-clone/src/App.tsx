import React from 'react';
import Button from './Custom/Button';
import {default as MaterialButton} from '@material-ui/core/Button';

const App: React.FC = () => {
    return (
        <div className="App">
            <h1>Material UI clone</h1>
            <h2>Button</h2>
            <div style={{display: 'grid', gridTemplateColumns: 'auto auto'}}>
                <div>
                    <Button>
                        Hello World
                    </Button>
                </div>
                <div>
                    <MaterialButton variant="contained" color="primary">
                        Hello World
                    </MaterialButton>
                </div>
            </div>
        </div>
    );
};

export default App;
