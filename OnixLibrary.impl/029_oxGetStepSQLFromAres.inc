function oxGetStepSQLFromAres(stepId: Integer; aresAcKey: String = nil): String;
begin
    Result := oxSQLExpWithParams('select CONVERT(varchar(max), acSQLExp) from tPA_SQLIStep where acKey = :p0 and anNo = :p1', [aresAcKey, stepId]);
end;




