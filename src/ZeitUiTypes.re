module String_or_stringArray = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let stringArray = (v: array(string)) => Any(v);
};

module String_or_bool = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let boolean = (v: bool) => Any(v);
};

module String_or_number = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let number = (v: float) => Any(v);
};

type placement = [
  | `top
  | `topStart
  | `topEnd
  | `left
  | `leftStart
  | `leftEnd
  | `bottom
  | `bottomStart
  | `bottomEnd
  | `right
  | `rightStart
  | `rightEnd
];

type modalBindings = {
  [@bs.as "open"]
  _open: bool,
  onClose: unit => unit,
};

type modal = {
  visible: bool,
  setVisible: bool => unit,
  currentRef: ReactDOMRe.Ref.t,
  bindings: modalBindings,
};

type inputBindings = {
  value: string,
  onChange: ReactEvent.Synthetic.t => unit,
};

type input = {
  state: string,
  setState: string => unit,
  currentRef: ReactDOMRe.Ref.t,
  reset: unit => unit,
  bindings: inputBindings,
};

type tabsBindings = {
  value: string,
  onChange: string => unit,
};

type tabs = {
  state: string,
  setState: string => unit,
  currentRef: ReactDOMRe.Ref.t,
  bindings: tabsBindings,
};
