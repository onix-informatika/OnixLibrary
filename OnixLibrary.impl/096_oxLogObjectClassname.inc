procedure oxLogObjectClassname(o: TObject; oName: String = 'nepoznato');
begin
    _macro.EventLogAdd(Format('Object "%s" has ClassName: "%s"', [oName, o.ClassName]));
end;




