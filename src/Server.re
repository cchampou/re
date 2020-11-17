print_endline("\r")
open Logger;

let fakeToken = "tokenToutPourri";

File.writeLineToFile(Config.localAccessTokenFilename, fakeToken);

let token = File.readFileFirstLine(Config.localAccessTokenFilename);

debug(token);
