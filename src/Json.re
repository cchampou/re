let createJsonString = dataList => {
  let enhancedTypes =
    List.map(((key, value)) => (key, `String(value)), dataList);
  let typedData = `Assoc(enhancedTypes);

  Yojson.Basic.pretty_to_string(typedData);
};
