       IDENTIFICATION DIVISION.
       PROGRAM-ID. DAY-2-P1-PROGRAM.
      
       ENVIRONMENT DIVISION.
       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
          SELECT INPUT-FILE ASSIGN TO 'input.txt'
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS IS SEQUENTIAL.
      
          SELECT OUTPUT-FILE ASSIGN TO 'output.txt'
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS IS SEQUENTIAL.
      
       DATA DIVISION.
       FILE SECTION.
       FD INPUT-FILE.
       01 INPUT-RECORD.
         05 LINE-CONTENT      PIC X(50).
      
       FD OUTPUT-FILE.
       01 OUTPUT-RECORD.
         05 OUTPUT-CONTENT    PIC 9(10).
      
       WORKING-STORAGE SECTION.
       01 PRIORITY-SUM         PIC 9(10) VALUE 0.
       01 PREFIX.
         05 PREFIX-CHAR       PIC X OCCURS 40 TIMES.
       01 SUFFIX.
         05 SUFFIX-CHAR       PIC X OCCURS 40 TIMES.
       01 EOF                  PIC X VALUE 'N'.
       01 INTERSECTION         PIC X.
      
       PROCEDURE DIVISION.
          OPEN INPUT INPUT-FILE
               OUTPUT OUTPUT-FILE.
      
          PERFORM READ-PROCESS-WRITE
      
          CLOSE INPUT-FILE
                OUTPUT-FILE.
      
          DISPLAY PRIORITY-SUM.
          STOP RUN.
      
       READ-PROCESS-WRITE.
          PERFORM UNTIL EOF = 'Y'
              READ INPUT-FILE
                  AT END
                      MOVE 'Y' TO EOF
                  NOT AT END
                      PERFORM CALCULATE-PRIORITY-SUM
                      MOVE PRIORITY-SUM TO OUTPUT-CONTENT
                      WRITE OUTPUT-RECORD
              END-READ
          END-PERFORM.
      
       CALCULATE-PRIORITY-SUM.
          MOVE LINE-CONTENT TO PREFIX
          COMPUTE MIDPOINT = FUNCTION LENGTH OF PREFIX / 2
      
          MOVE PREFIX(1:MIDPOINT) TO PREFIX
          MOVE PREFIX(MIDPOINT + 1:FUNCTION LENGTH OF PREFIX) TO SUFFIX
      
          PERFORM VARYING I FROM 1 BY 1 
          UNTIL I > FUNCTION LENGTH OF PREFIX
              MOVE PREFIX(I:1) TO INTERSECTION
              IF SUFFIX CONTAINS INTERSECTION
                  IF INTERSECTION IS NUMERIC
                      ADD FUNCTION NUMVAL(INTERSECTION) TO PRIORITY-SUM
                  ELSE
                      ADD (FUNCTION ORD(INTERSECTION) - 
                      FUNCTION ORD('A') + 1) TO PRIORITY-SUM
                  END-IF
                  EXIT PERFORM
              END-IF
          END-PERFORM.
