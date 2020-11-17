open Yojson.Basic.Util;

let getRemoteAccessToken = () => {
  let data =
    Json.createJsonString([
      ("client_id", Config.clientId),
      ("client_secret", Config.clientSecret),
      ("grant_type", "client_credentials"),
    ]);

  let headers =
    NetUtils.addHeader(
      Cohttp.Header.init(),
      ("content-type", "application/json"),
    );

  NetUtils.postRequest(~url=Config.twitchAuthApi, ~headers, ~data)
  |> Yojson.Basic.from_string
  |> member("access_token")
  |> to_string;
};

let validateToken = token => {
  let headers =
    NetUtils.addHeader(
      Cohttp.Header.init(),
      ("Authorization", "Bearer " ++ token),
    );

  Logger.debug(Config.twitchAuthValidateApi);
  NetUtils.getRequest(~url=Config.twitchAuthValidateApi, ~headers);
};
