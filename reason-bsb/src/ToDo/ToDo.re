[@react.component]
let make = () => {
  let (task, setTask) = React.useState(_ => "");
  let (taskList, setTaskList) = React.useState(_ => []);

  let handleAdd = _ => {
    setTaskList(_ => taskList @ [task]);
    setTask(_ => "");
  };

  let handleReset = _ => {
    setTaskList(_ => []);
    setTask(_ => "");
  };

  <div>
    <h1> {React.string("Simple ToDo list")} </h1>
    <ul>
      {React.array(
         Array.of_list(
           List.map(item => <li> {React.string(item)} </li>, taskList),
         ),
       )}
    </ul>
    <input
      name="task"
      style=ToDoStyles.inputStyle
      value=task
      onChange={_event => setTask(ReactEvent.Form.target(_event)##value)}
    />
    <button style=ToDoStyles.buttonStyle onClick=handleAdd>
      {React.string("ADD")}
    </button>
    <button style=ToDoStyles.buttonStyle onClick=handleReset>
      {React.string("RESET")}
    </button>
  </div>;
};
