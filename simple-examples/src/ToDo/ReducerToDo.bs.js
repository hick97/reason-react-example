'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var ToDoStyles$MyReactApp = require("./styles/ToDoStyles.bs.js");

var initialState = {
  task: {
    id: 0,
    value: ""
  },
  taskList: /* [] */0,
  error: ""
};

function reducer(state, action) {
  if (typeof action === "number") {
    return initialState;
  }
  switch (action.TAG | 0) {
    case /* AddToList */0 :
        return {
                task: {
                  id: 0,
                  value: ""
                },
                taskList: Pervasives.$at(state.taskList, {
                      hd: action._0,
                      tl: /* [] */0
                    }),
                error: state.error
              };
    case /* RemoveFromList */1 :
        var value = action._0;
        return {
                task: state.task,
                taskList: List.filter(function (item) {
                        return item.id !== value;
                      })(state.taskList),
                error: state.error
              };
    case /* HandleErrors */2 :
        return {
                task: state.task,
                taskList: state.taskList,
                error: action._0
              };
    
  }
}

function ReducerToDo(Props) {
  var match = React.useReducer(reducer, initialState);
  var dispatch = match[1];
  var state = match[0];
  var match$1 = React.useState(function () {
        return "";
      });
  var setInput = match$1[1];
  var input = match$1[0];
  var onSubmit = function (param) {
    if (input === "") {
      return Curry._1(dispatch, {
                  TAG: /* HandleErrors */2,
                  _0: "This field is required!"
                });
    }
    var newTask_id = List.length(state.taskList) + 1 | 0;
    var newTask = {
      id: newTask_id,
      value: input
    };
    Curry._1(dispatch, {
          TAG: /* AddToList */0,
          _0: newTask
        });
    Curry._1(dispatch, {
          TAG: /* HandleErrors */2,
          _0: ""
        });
    return Curry._1(setInput, (function (param) {
                  return "";
                }));
  };
  return React.createElement("div", undefined, React.createElement("ul", undefined, $$Array.of_list(List.map((function (item) {
                            return React.createElement("li", undefined, item.value + (" - " + String(item.id)), React.createElement("button", {
                                            style: ToDoStyles$MyReactApp.buttonStyle,
                                            onClick: (function (_event) {
                                                return Curry._1(dispatch, {
                                                            TAG: /* RemoveFromList */1,
                                                            _0: item.id
                                                          });
                                              })
                                          }, "REMOVE"));
                          }), state.taskList))), React.createElement("input", {
                  style: ToDoStyles$MyReactApp.inputStyle,
                  name: "task",
                  value: input,
                  onChange: (function (_event) {
                      return Curry._1(setInput, _event.target.value);
                    })
                }), React.createElement("button", {
                  style: ToDoStyles$MyReactApp.buttonStyle,
                  onClick: onSubmit
                }, "ADD"), React.createElement("button", {
                  style: ToDoStyles$MyReactApp.buttonStyle,
                  onClick: (function (_event) {
                      return Curry._1(dispatch, /* Reset */0);
                    })
                }, "RESET"), React.createElement("p", {
                  style: ToDoStyles$MyReactApp.alertStyle
                }, state.error));
}

var make = ReducerToDo;

exports.initialState = initialState;
exports.reducer = reducer;
exports.make = make;
/* react Not a pure module */
