open Printf;

let readFileFirstLine = filename =>
  switch (open_in(filename)) {
  | exception _ => None
  | ic =>
    switch (input_line(ic)) {
    | line =>
      flush(stdout);
      close_in(ic);
      Some(line);
    | exception _ => None;
    }
  };

let writeLineToFile = (filename, line) => {
  let oc = open_out(filename);
  fprintf(oc, "%s", line);
  close_out(oc);
};
