[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | [] => <BlinkingGreeting> {React.string("Hello!")} </BlinkingGreeting>
  | ["reason-using-js"] => <ReasonUsingJS />
  | ["counter"] => <Counter />
  | ["counter-reducer"] => <CounterWithReducer />
  | ["todo"] => <ToDo />
  | ["todo-reducer"] => <ToDoWithReducer />
  | _ => <div> {"Page not found :/" |> ReasonReact.string} </div>
  };
};
