function oxStreamToString(Stream: TStream): string;
var
  SS: TStringStream;
begin
  Result := '';
  if Stream <> nil then
  begin
    Stream.Position := 0;  // Reset the position to the beginning of the stream
    SS := TStringStream.Create('');
    try
      SS.CopyFrom(Stream, Stream.Size);  // Copy the entire stream
      Result := SS.DataString;  // Get the string representation
    finally
      SS.Free;
    end;
  end;
end;




