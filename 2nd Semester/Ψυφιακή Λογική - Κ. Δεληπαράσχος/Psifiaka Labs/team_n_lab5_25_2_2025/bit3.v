module bit3(updown,CLKP,QA,QB,QC);

input updown,CLKP;
output QA,QB,QC;

wire wQA_not,wQB_not,wQC_not,wnotupdow,wauq,wand3,wor1,wand2,wor2,wand4;
ex1 FFA(1, CLKP, 1,QA,wQA_not);
ex1 FFB(wor1, CLKP,wor1, QB,wQB_not);
ex1 FFC(wor2, CLKP,wor2,QC,wQC_not);

not not_updown(wnotupdow,updown);
and and_updown_qa(wauq, updown, QA);
and and2(wand2,wnotupdow,wQA_not);
or or1(wor1,wand2,QA);
and and3(wand3, wand2,wQB_not);
and and4(wand4, wauq, QB);
or or2(wor2,wand4,wand3);

endmodule