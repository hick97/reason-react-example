'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var ToDoStyles$MyReactApp = require("./styles/ToDoStyles.bs.js");

function ToDo(Props) {
  var match = React.useState(function () {
        return "";
      });
  var setTask = match[1];
  var task = match[0];
  var match$1 = React.useState(function () {
        return /* [] */0;
      });
  var setTaskList = match$1[1];
  var taskList = match$1[0];
  var handleAdd = function (param) {
    Curry._1(setTaskList, (function (param) {
            return Pervasives.$at(taskList, {
                        hd: task,
                        tl: /* [] */0
                      });
          }));
    return Curry._1(setTask, (function (param) {
                  return "";
                }));
  };
  var handleReset = function (param) {
    Curry._1(setTaskList, (function (param) {
            return /* [] */0;
          }));
    return Curry._1(setTask, (function (param) {
                  return "";
                }));
  };
  return React.createElement("div", undefined, React.createElement("ul", undefined, $$Array.of_list(List.map((function (item) {
                            return React.createElement("li", undefined, item);
                          }), taskList))), React.createElement("input", {
                  style: ToDoStyles$MyReactApp.inputStyle,
                  name: "task",
                  value: task,
                  onChange: (function (_event) {
                      return Curry._1(setTask, _event.target.value);
                    })
                }), React.createElement("button", {
                  style: ToDoStyles$MyReactApp.buttonStyle,
                  onClick: handleAdd
                }, "ADD"), React.createElement("button", {
                  style: ToDoStyles$MyReactApp.buttonStyle,
                  onClick: handleReset
                }, "RESET"));
}

var make = ToDo;

exports.make = make;
/* react Not a pure module */
