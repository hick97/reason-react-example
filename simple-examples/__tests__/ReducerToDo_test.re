open Jest;
open Expect;
open ReactTestingLibrary;

describe("<ReducerToDo />", () => {
  test("should print a error message when input is empty", () => {
    let result = <ReducerToDo /> |> render;

    act(() =>
      result |> getByText(~matcher=`Str("ADD")) |> FireEvent.click |> ignore
    );

    result
    |> getByText(~matcher=`Str("This field is required!"))
    |> expect
    |> toMatchSnapshot;
  })
});
