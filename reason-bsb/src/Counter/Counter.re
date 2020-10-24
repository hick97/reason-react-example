[@react.component]
let make = () => {
  let (count, setCount) = React.useState(_ => 0);
  let (error, setError) = React.useState(_ => "");

  let handleDecrement = _ => {
    switch (count) {
    | 0 => setError(_ => "Counter cannot be negative!")
    | _ => setCount(prev => prev - 1)
    };
  };

  let handleIncrement = _ => {
    setCount(prev => prev + 1);
  };

  let handleReset = _ => {
    setCount(_ => 0);
    setError(_ => "");
  };

  <div>
    <p> {React.string("Counter: " ++ string_of_int(count))} </p>
    <button style=CounterStyles.buttonStyle onClick=handleIncrement>
      {React.string("+")}
    </button>
    <button style=CounterStyles.buttonStyle onClick=handleDecrement>
      {React.string("-")}
    </button>
    <button style=CounterStyles.buttonStyle onClick=handleReset>
      {React.string("Reset")}
    </button>
    <span> {React.string(error)} </span>
  </div>;
};
