       IDENTIFICATION DIVISION.
       PROGRAM-ID. DAY_1_P1-PROGRAM.
      
      
       ENVIRONMENT DIVISION.
       INPUT-OUTPUT SECTION.
          FILE-CONTROL.
              SELECT INPUT-FILE ASSIGN TO 'input.txt'
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
      
              SELECT OUTPUT-FILE ASSIGN TO 'output.txt'
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
      
      
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
       01 SUMMATION            PIC 9(10).
       01 FIRST-SUM            PIC 9(10).
       01 SECOND-SUM           PIC 9(10).
       01 THIRD-SUM            PIC 9(10).
       01 EOF                  PIC X(1)  VALUE 'N'.
      
      
       PROCEDURE DIVISION.
           OPEN INPUT INPUT-FILE
                OUTPUT OUTPUT-FILE.
           
           PERFORM UNTIL EOF = 'Y'
                   READ INPUT-FILE
                   AT END
                      MOVE 'Y' TO EOF
                   NOT AT END
                       PERFORM PROCESS-LINE
                   END-READ
           END-PERFORM.
      
           ADD FIRST-SUM, SECOND-SUM, THIRD-SUM GIVING MAX-SUM-OUTPUT.
           DISPLAY MAX-SUM-OUTPUT
           WRITE OUTPUT-RECORD.
           CLOSE INPUT-FILE
                 OUTPUT-FILE.
           STOP RUN.
      
      
       PROCESS-LINE.
           IF LINE-CONTENT NOT EQUAL SPACES
              COMPUTE LINE-CONTENT-NUM = FUNCTION NUMVAL(LINE-CONTENT) 
              ADD LINE-CONTENT-NUM TO SUMMATION
           ELSE
              IF SUMMATION > FIRST-SUM 
                 MOVE SECOND-SUM TO THIRD-SUM 
                 MOVE FIRST-SUM TO SECOND-SUM 
                 MOVE SUMMATION TO FIRST-SUM 
              ELSE
                 IF SUMMATION > SECOND-SUM 
                    MOVE SECOND-SUM TO THIRD-SUM 
                    MOVE SUMMATION TO SECOND-SUM 
                 ELSE
                    IF SUMMATION > THIRD-SUM
                       MOVE SUMMATION TO THIRD-SUM 
                    END-IF
                 END-IF
              END-IF
              MOVE ZERO TO SUMMATION
           END-IF.