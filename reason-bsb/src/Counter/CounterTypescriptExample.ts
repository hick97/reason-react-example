// Used for illustrative and comparative purposes only

interface State {
  count: number;
}

/* Initial state */
const defaultState: State = {
  count: 0,
};

export const INCREMENT = "INCREMENT";
export const DECREMENT = "DECREMENT";
export const RESET = "RESET";

interface IncrementCountAction {
  type: typeof INCREMENT;
}

interface DecrementCountAction {
  type: typeof DECREMENT;
}

interface ResetAction {
  type: typeof RESET;
}

type ActionTypes = IncrementCountAction | DecrementCountAction | ResetAction;

/* Actions */
export function incrementCount(): ActionTypes {
  return {
    type: INCREMENT,
  };
}

export function decrementCount(): ActionTypes {
  return {
    type: DECREMENT,
  };
}

export function reset(): ActionTypes {
  return {
    type: RESET,
  };
}

/* Reducer */
const reducer = (state: State, action: ActionTypes) => {
  switch (action.type) {
    case INCREMENT:
      return { count: state.count + 1 };
    case DECREMENT:
      return { count: state.count + 1 };
    case RESET:
      return defaultState;
    default:
      return state;
  }
};
