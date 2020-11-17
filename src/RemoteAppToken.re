open Lwt;
open Cohttp_lwt_unix;

let getRemoteAccessToken = {
  let typedData =
    `Assoc([
      ("client_id", `String(Config.clientId)),
      ("client_secret", `String(Config.clientSecret)),
      ("grant_type", `String("client_credentials")),
    ]);

  let data = Yojson.Basic.pretty_to_string(typedData);

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
  print_endline(body);
};
