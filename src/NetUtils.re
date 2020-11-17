
open Lwt;
open Cohttp_lwt_unix;


let addHeader = (
  headers: Cohttp.Header.t,
  (key: string, value: string)
): Cohttp.Header.t => {
  Cohttp.Header.add(headers, key, value);
}


let postRequest = (
  ~url: string,
  ~headers: Cohttp.Header.t = Cohttp.Header.init(),
  ~data: string,
) => {

  let request =
    Client.post(
      ~body=Cohttp_lwt.Body.of_string(data),
      ~headers=headers,
      Uri.of_string(url),
    )
    >>= (((_, body)) => Cohttp_lwt.Body.to_string(body));

  let response = Lwt_main.run(request);
  response;
}

let getRequest = (
  ~url: string,
  ~headers: Cohttp.Header.t,
) => {

  let request =
    Client.get(
      ~headers=headers,
      Uri.of_string(url),
    )
    >>= (((_, body)) => Cohttp_lwt.Body.to_string(body));

  let response = Lwt_main.run(request);
  response;
}
