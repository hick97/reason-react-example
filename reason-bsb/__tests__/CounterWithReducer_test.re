open Jest;
open Expect;
open ReactTestingLibrary;

describe("<CounterWithReducer />", () => {
  test("should show the correct counter value when +1 is clicked", () => {
    let result = <CounterWithReducer /> |> render;

    act(() =>
      result |> getByText(~matcher=`Str("+1")) |> FireEvent.click |> ignore
    );

    result
    |> getByText(~matcher=`Str("Counter: 1"))
    |> expect
    |> toMatchSnapshot;
  });

  test("should show the correct counter value when +100 is clicked", () => {
    let result = <CounterWithReducer /> |> render;

    act(() =>
      result |> getByText(~matcher=`Str("+100")) |> FireEvent.click |> ignore
    );

    result
    |> getByText(~matcher=`Str("Counter: 100"))
    |> expect
    |> toMatchSnapshot;
  });

  test(
    "should show the correct counter value when -1 is clicked after +100", () => {
    let result = <CounterWithReducer /> |> render;

    act(() =>
      result |> getByText(~matcher=`Str("+100")) |> FireEvent.click |> ignore
    );

    act(() =>
      result |> getByText(~matcher=`Str("-1")) |> FireEvent.click |> ignore
    );

    result
    |> getByText(~matcher=`Str("Counter: 99"))
    |> expect
    |> toMatchSnapshot;
  });

  test(
    "should show the correct counter value when Reset button is clicked", () => {
    let result = <CounterWithReducer /> |> render;

    act(() =>
      result |> getByText(~matcher=`Str("+100")) |> FireEvent.click |> ignore
    );

    act(() =>
      result
      |> getByText(~matcher=`Str("Reset"))
      |> FireEvent.click
      |> ignore
    );

    result
    |> getByText(~matcher=`Str("Counter: 0"))
    |> expect
    |> toMatchSnapshot;
  });

  test(
    "should show an error message when -1 is clicked and counter is zero", () => {
    let result = <CounterWithReducer /> |> render;

    act(() =>
      result |> getByText(~matcher=`Str("-1")) |> FireEvent.click |> ignore
    );

    result
    |> getByText(~matcher=`Str("Counter cannot be negative!"))
    |> expect
    |> toMatchSnapshot;
  });
});
