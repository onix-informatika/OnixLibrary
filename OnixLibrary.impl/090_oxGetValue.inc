function oxGetValue(ofElement: String): String;
var comp: TComponent;
begin
    comp := OwnerForm.FindComponent(ofElement);
    
    if not assigned(comp) then
    begin               
        ShowMessage(ofElement + ' ne postoji');
    end else
    begin    
        _macro.eventlogadd('Element '  + ofElement + ' postoji, testiram vrstu'); // ovdje naredati sve moguce class opcije za koje zelimo implentirati trazenje vrijednosti
    if comp is TdlcxLabeledDBTextEdit then Result := TdlcxLabeledDBTextEdit(comp).EditingValue
        else if comp is TdlcxLabeledNumberEdit then Result := TdlcxLabeledNumberEdit(comp).EditingValue
    else if comp is TDaDBLookupComboBox then Result := TDaDBLookupComboBox(comp).EditingValue
    else if comp is TDaLookupComboBox then Result := TDaLookupComboBox(comp).EditingValue
        else showmessage('Nije implementirana vrsta za ' + ofElement + ': ' + comp.classname);
    end;
    
    _macro.eventlogadd('Element '  + ofElement +  ' postoji s value: ' + Result);
end;




