function oxTransliterate(const Text: string): string;
var
  i: Integer;
begin
  Result := Text;
  for i := 1 to Length(Result) do
  begin
    case Result[i] of
      ' ', ' ': Result[i] := 'c';
      ' ': Result[i] := 's';
      ' ': Result[i] := 'd';
      ' ': Result[i] := 'z';
      ' ', ' ': Result[i] := 'C';
      ' ': Result[i] := 'S';
      ' ': Result[i] := 'D';
      ' ': Result[i] := 'Z';
      ' ', 'a', ' ', ' ', 'a': Result[i] := 'a';
      ' ', 'A', ' ', ' ', 'A': Result[i] := 'A';
      ' ', 'e', ' ', 'e': Result[i] := 'e';
      ' ', 'E', ' ', 'E': Result[i] := 'E';
      ' ', 'i', 'i', ' ': Result[i] := 'i';
      ' ', 'I', 'I', ' ': Result[i] := 'I';
      ' ', 'o', ' ', ' ', 'o': Result[i] := 'o';
      ' ', 'O', ' ', ' ', 'O': Result[i] := 'O';
      ' ', 'u', ' ', 'u': Result[i] := 'u';
      ' ', 'U', ' ', 'U': Result[i] := 'U';
      // Add any other special characters and their replacements here
    end;
  end;
end;





