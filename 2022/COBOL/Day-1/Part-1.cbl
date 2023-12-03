      ******************************************************************
      **                IDENTIFICATION DIVISION                        *
      ******************************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. DAY_1-PROGRAM.

       ENVIRONMENT DIVISION.
       INPUT-OUTPUT SECTION.
          FILE-CONTROL.
              SELECT INPUT-FILE ASSIGN TO 'input.txt'
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS IS SEQUENTIAL.

              SELECT OUTPUT-FILE ASSIGN TO 'output.txt'
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS IS SEQUENTIAL.
      ******************************************************************
      **                    DATA DIVISION                             **
      ******************************************************************
       DATA DIVISION.
       FILE SECTION.
          FD INPUT-FILE.
       01 INPUT-RECORD.
          05 LINE-CONTENT      PIC X(10).
          05 LINE-CONTENT-NUM  PIC 9(10).

          FD OUTPUT-FILE.
       01 OUTPUT-RECORD.
          05 MAX-SUM-OUTPUT    PIC 9(10).

       WORKING-STORAGE SECTION.
       01 MAX-SUM              PIC 9(10).
       01 SUMMATION            PIC 9(10).
       01 EOF                  PIC X     VALUE 'N'.
       
      ******************************************************************
      **                 PROCEDURE DIVISION                           **
      ******************************************************************
       PROCEDURE DIVISION.
           OPEN INPUT INPUT-FILE
                OUTPUT OUTPUT-FILE.
      **
      **   Read from input.txt
      **
           PERFORM UNTIL EOF = 'Y'
                   READ INPUT-FILE
                   AT END
                      MOVE 'Y' TO EOF
                   NOT AT END
                       PERFORM PROCESS-LINE
                   END-READ
           END-PERFORM.
      **
      **   Write to output.txt
      **
           DISPLAY MAX-SUM.
           MOVE MAX-SUM TO MAX-SUM-OUTPUT.
           WRITE OUTPUT-RECORD.
           CLOSE INPUT-FILE
                 OUTPUT-FILE.
           STOP RUN.
      
      **----------------------------------------------------------------
      
       PROCESS-LINE.
           IF LINE-CONTENT NOT EQUAL SPACES
              COMPUTE LINE-CONTENT-NUM = FUNCTION NUMVAL(LINE-CONTENT) 
              ADD LINE-CONTENT-NUM TO SUMMATION
           ELSE
              IF SUMMATION GREATER THAN MAX-SUM

                 MOVE SUMMATION TO MAX-SUM
      
              END-IF
              MOVE ZERO TO SUMMATION
           END-IF.