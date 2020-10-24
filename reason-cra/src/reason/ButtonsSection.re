let buttonStyles =
  ReactDOMRe.Style.make(
    ~backgroundColor="white",
    ~border="1px solid #48a9dc",
    ~borderRadius="4px",
    ~color="#48a9dc",
    ~cursor="pointer",
    ~fontSize="16px",
    ~fontWeight="bold",
    ~margin="10px 10px 0 0",
    ~outline="none",
    ~padding="10px",
    ~width="120px",
    (),
  );

[@react.component]
let make = (~handleIncrement, ~handleDecrement, ~handleReset) =>
  <div>
    <button style=buttonStyles onClick=handleIncrement>
      {React.string("+")}
    </button>
    <button style=buttonStyles onClick=handleDecrement>
      {React.string("-")}
    </button>
    <button style=buttonStyles onClick=handleReset>
      {React.string("Reset")}
    </button>
  </div>;
