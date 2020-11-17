

type t =
  | Debug
  | Warn
  | Err;



let log = (lvl, msg) => {

  switch (lvl) {
  | Debug => print_endline("[debug] " ++ msg)
  | Warn => print_endline("[warning] " ++ msg)
  | Err => print_endline("[error] " ++ msg)
  }
}

let debug = log(Debug);
let warn = log(Warn);
let err = log(Err);
