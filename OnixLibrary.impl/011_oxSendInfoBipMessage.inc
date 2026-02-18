 function oxSendInfoBipMessage(const BaseURL, APIKey, Sender, Recipient, MessageText: String): String;
var
  request: TclHTTP;
  response: TStringList;
  URL: String;
  jsonRequest: TclJSONObject;
  jsonMessage, jsonDestinations: TclJSONObject;
  jsonMessagesArray, jsonDestinationsArray: TclJSONArray;
  RequestStream: TStringStream;
  RequestStrings: TStringList;
  jsonLanguages: TclJSONObject;
  acPhone: String;
begin
  if BaseURL.EndsWith('/') then
  begin
    URL := BaseURL + 'sms/2/text/advanced';
  end else
  begin
    URL := BaseURL + '/sms/2/text/advanced';
  end;

  request := TclHTTP.Create(nil);
  response := TStringList.Create();
  RequestStrings := TStringList.Create();
  jsonRequest := TclJSONObject.Create();

  try
    // Construct the JSON payload
    jsonMessagesArray := TclJSONArray.Create();
    jsonRequest.AddMember('messages', jsonMessagesArray);
    
    jsonMessage := TclJSONObject.Create();
    jsonMessagesArray.Add(jsonMessage);
    jsonMessage.AddString('from', Sender);
    jsonMessage.AddString('text', MessageText);
    
    //jsonLanguages := TclJSONObject.Create();
    //jsonLanguages.AddString('languageCode', 'HR'); 
    //jsonMessage.AddMember('language', jsonLanguages);

    // Create destinations array and add a destination object
    jsonDestinationsArray := TclJSONArray.Create();
    jsonMessage.AddMember('destinations', jsonDestinationsArray);
                 
    for acPhone in Recipient.Split(';') do
    begin    
        jsonDestinations := TclJSONObject.Create();
        jsonDestinationsArray.Add(jsonDestinations);
        jsonDestinations.AddString('to', oxOnlyASCIILetterAndNumbers(EnsureCountryCode(acPhone, '00385')));
    end;

    // Convert the JSON object to a string and add it to the request source 
    //RequestStream := TStringStream.Create(jsonRequest.GETJsonString(), TEncoding.UTF8);
    RequestStrings := TStringList.Create();
    RequestStrings.Add(jsonRequest.GETJsonString()); 
    request.Request := TclHTTPRequest.Create(request);
    //request.Request.RequestSource := RequestStrings; // Assuming you can set RequestSource directly
    request.Request.RequestSource := RequestStrings; // Assuming you can set RequestSource directly
    
    // Set up the HTTP request
    request.UseTLS := ctAutomatic;
    request.TLSFlags := []; 
    request.SilentHTTP := true;              
    request.Request.HeaderSource.Add('Content-Type: application/json');
    request.Request.HeaderSource.Add('Authorization: App ' + APIKey);

    // Send the request
    request.Post(URL, response);
    
    _macro.EventLogAdd(response.Text);
    
    Result := response.Text;
  finally
    jsonRequest.Free;
    request.Free;
    response.Free;
    RequestStrings.Free;
  end;
end;




