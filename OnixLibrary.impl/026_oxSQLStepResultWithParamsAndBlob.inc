function oxSQLStepResultWithParamsAndBlob(stepId: Integer; blob: TStream; params: array of Variant): String;
var stepSQL: String;
begin
    stepSQL := oxGetStepSQLFromAres(stepId, Ares.AcKey);
    result := oxSQLExpWithBlob(stepSQL, blob, params);
end;




