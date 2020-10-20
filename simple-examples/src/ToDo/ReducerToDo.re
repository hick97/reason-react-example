// types
type task = {
  id: int,
  value: string,
};

type state = {
  task,
  taskList: list(task),
  error: string,
};

// variants
type action =
  | Reset
  | AddToList(task)
  | RemoveFromList(int)
  | HandleErrors(string);

// records
let initialState = {
  task: {
    id: 0,
    value: "",
  },
  taskList: [],
  error: "",
};

// reducer
let reducer = (state, action) => {
  switch (action) {
  | AddToList(value) => {
      ...state,
      task: initialState.task,
      taskList: state.taskList @ [value],
    }
  | RemoveFromList(value) => {
      ...state,
      taskList: List.filter(item => item.id !== value, state.taskList),
    }
  | Reset => initialState
  | HandleErrors(err) => {...state, error: err}
  };
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let (input, setInput) = React.useState(_ => "");

  let onSubmit = _ => {
    switch (input) {
    | "" => dispatch(HandleErrors("This field is required!"))
    | message =>
      let newTask = {id: List.length(state.taskList) + 1, value: message};
      dispatch(AddToList(newTask));
      dispatch(HandleErrors(""));
      setInput(_ => "");
    };
  };

  <div>
    <ul>
      {React.array(
         Array.of_list(
           List.map(
             item =>
               <li>
                 {React.string(item.value ++ " - " ++ string_of_int(item.id))}
                 <button
                   style=ToDoStyles.buttonStyle
                   onClick={_event => dispatch(RemoveFromList(item.id))}>
                   {React.string("REMOVE")}
                 </button>
               </li>,
             state.taskList,
           ),
         ),
       )}
    </ul>
    <label htmlFor="task-input"> {React.string("Write a task:")} </label>
    <input
      name="task-input"
      style=ToDoStyles.inputStyle
      value=input
      onChange={_event => setInput(ReactEvent.Form.target(_event)##value)}
    />
    <button style=ToDoStyles.buttonStyle onClick=onSubmit>
      {React.string("ADD")}
    </button>
    <button style=ToDoStyles.buttonStyle onClick={_event => dispatch(Reset)}>
      {React.string("RESET")}
    </button>
    <p style=ToDoStyles.alertStyle> {React.string(state.error)} </p>
  </div>;
};
