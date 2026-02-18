function oxAsAcKey(someText: String): String;
var yearPart: String;
    docPart: String;
    counterPart: String;
begin
    if someText.IndexOf('-') <> -1 then
    begin                 
        yearPart := COPY(someText,0,2);
        docPart := COPY(someText,4,3);
        counterPart := COPY(someText,8, 20);
        _macro.eventlogadd(Format('Parsed someText with: Year: [%s], Doc: [%s], Counter: [%s]', [yearPart, docPart, counterPart]));
        Result := yearPart + docPart +'00'+ counterPart;
    end
    else Result := someText;
    Result := TRIM(Result);
    _macro.eventlogadd('oxAsAcKey returning: ' + Result);
end;




