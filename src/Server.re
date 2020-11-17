print_endline("\r");
open Logger;

let previousToken = File.readFileFirstLine(Config.localAccessTokenFilename);

let token =
  switch (previousToken) {
  | Some(token) =>
    debug("Local token found, validating");
    let validation = RemoteAppToken.validateToken(token);
    debug(validation);
    token;
  | None =>
    warn("Local token not found, getting new one");
    RemoteAppToken.getRemoteAccessToken();
  };

File.writeLineToFile(Config.localAccessTokenFilename, token);
