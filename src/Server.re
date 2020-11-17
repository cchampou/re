print_endline("\r");
open Logger;
open Yojson.Basic.Util;

let previousToken = File.readFileFirstLine(Config.localAccessTokenFilename);

let token =
  switch (previousToken) {
  | Some(data) =>
    debug("Local token found");
    data;
  | None =>
    warn("Local token not found, getting new one");
    let jsonData =
      RemoteAppToken.getRemoteAccessToken() |> Yojson.Basic.from_string;
    jsonData |> member("access_token") |> to_string;
  };

File.writeLineToFile(Config.localAccessTokenFilename, token);
