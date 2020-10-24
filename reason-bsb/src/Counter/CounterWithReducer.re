// types -> interfaces
type state = {
  count: int,
  error: string,
};

// variants ->  constructors
type actions =
  | Increment(int)
  | Decrement
  | Reset
  | HandleError(string);

// records -> objects
let initialState = {count: 0, error: ""};

// pattern matching -> switch case
let reducer = (state, action) => {
  switch (action) {
  | Increment(k) => {error: initialState.error, count: state.count + k}
  | Decrement => {...state, count: state.count - 1}
  | Reset => initialState
  | HandleError(err) => {...state, error: err}
  };
};

[@react.component]
let make = () => {
  // Using React hook (useReducer)
  let (state, dispatch) = React.useReducer(reducer, initialState);

  let handleDecrement = _ => {
    switch (state.count) {
    | 0 => dispatch(HandleError("Counter cannot be negative!"))
    | _ => dispatch(Decrement)
    };
  };

  let handleIncrement = _ => {
    dispatch(Increment(1));
  };

  let handleReset = _ => {
    dispatch(Reset);
  };

  <div>
    <p> {React.string("Counter: " ++ string_of_int(state.count))} </p>
    <button style=CounterStyles.buttonStyle onClick=handleIncrement>
      {React.string("+1")}
    </button>
    <button
      style=CounterStyles.buttonStyle
      onClick={_ => dispatch(Increment(100))}>
      {React.string("+100")}
    </button>
    <button style=CounterStyles.buttonStyle onClick=handleDecrement>
      {React.string("-1")}
    </button>
    <button style=CounterStyles.buttonStyle onClick=handleReset>
      {React.string("Reset")}
    </button>
    <span> {React.string(state.error)} </span>
  </div>;
};
