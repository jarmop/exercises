import React, {FunctionComponent} from 'react';

import './Button.css';

type ButtonProps = {
    variant?: string,
    color?: string,
};

const Button: FunctionComponent<ButtonProps> = ({variant, color, children}) => (
    <button
        className="button"
    >
        {children}
    </button>
);

export default Button;