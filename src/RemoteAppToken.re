open Lwt;
open Cohttp_lwt_unix;

let getRemoteAccessToken = () => {
  let data =
    Json.createJsonString([
      ("client_id", Config.clientId),
      ("client_secret", Config.clientSecret),
      ("grant_type", "client_credentials"),
    ]);

  let headers =
    Cohttp.Header.add(
      Cohttp.Header.init(),
      "content-type",
      "application/json",
    );

  let body =
    Client.post(
      ~body=Cohttp_lwt.Body.of_string(data),
      ~headers,
      Uri.of_string(Config.twitchAuthApi),
    )
    >>= (((_, body)) => Cohttp_lwt.Body.to_string(body));

  let body = Lwt_main.run(body);
  body;
};
