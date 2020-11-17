print_endline("\r")
open Logger;


let previousToken = File.readFileFirstLine(Config.localAccessTokenFilename);

switch(previousToken) {
  | Some(data) => debug(data)
  | None => warn("Line not found");
}

let fakeToken = "tokenToutPourri";

File.writeLineToFile(Config.localAccessTokenFilename, fakeToken);


