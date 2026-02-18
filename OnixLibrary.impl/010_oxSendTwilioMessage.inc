function oxSendTwilioMessage(const AccountSID, AuthToken, ToNumber, FromNumber, MessageBody: String): String;
 var request: TclHTTP;
     response: TStringList;
     URL: String;
 begin
     URL := Format('https://api.twilio.com/2010-04-01/Accounts/%s/Messages.json', [AccountSID]);
     response := TStringList.Create();
     request := TclHTTP.Create(nil); 
     request.UseTLS := ctAutomatic; 
     request.TLSFlags := [];
     request.Request := TclHTTPRequest.Create(request);
     request.Request.HeaderSource.Add('Content-Type: application/x-www-form-urlencoded');
     request.SilentHTTP := true;              
     request.UserName := AccountSID;
     request.Password := AuthToken;
     request.Request.ClearItems(); 
     request.Request.AddFormField('To', ToNumber);
     request.Request.AddFormField('From', FromNumber);
     request.Request.AddFormField('Body', MessageBody);
     request.Post(URL, response);
     _macro.EventLogAdd(response.text);
     Result := response.text;
 end;




