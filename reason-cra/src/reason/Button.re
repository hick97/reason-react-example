let buttonStyles =
  ReactDOMRe.Style.make(
    ~borderRadius="4px 4px 4px 4px",
    ~marginTop="10px",
    ~padding="10px",
    ~backgroundColor="white",
    ~cursor="pointer",
    (),
  );

[@react.component]
let make = (~name) =>
  <button style=buttonStyles> {React.string("Hello " ++ name)} </button>;
