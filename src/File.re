open Printf;
open Logger;

let readFileFirstLine = filename => {
  debug("Starting reading sequence for file " ++ filename);

  let ic = open_in(filename);

  let line = input_line(ic);

  flush(stdout);
  close_in(ic);

  debug("Reading sequence complete, file closed");

  line;
};


let writeLineToFile = (filename, line) => {
  debug("Starting writing to file" ++ filename);

  let oc = open_out(filename);

  fprintf(oc, "%s", line);

  close_out(oc);

  debug("Writing sequence complete, file closed");
}
