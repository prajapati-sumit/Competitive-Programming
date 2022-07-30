4. How to check an assignment for plagiarism



Let’s consider my midterm exam. To check this exam for plagiarism, we just need to 1) organize the files and 2) submit the request to the server.
Organize the files.
Each exam submission consists of one .java file. All these files should be in the same directory, according to MOSS requirements. We can create a directory at /Applications/MOSS/Midterm_Exam/and put all the submissions inside it.
Terminal output:
(base) me@Briennas-MBP MOSS % ls
Midterm_Exam moss.pl
(base) me@Briennas-MBP MOSS % cd Midterm_Exam
(base) me@Briennas-MBP Midterm_Exam % ls
A.java C.java E.java G.java I.java K.java
B.java D.java F.java H.java J.java L.java
For confidentiality, I changed each student’s name to an arbitrary letter ID, but I usually use their real names, e.g. jane_doe.java.
Submit the request to the server.
From the Midterm_Exam directory, we can submit the request:
../moss.pl -l java -c "Midterm Exam" ./*.java
General syntax:
[path/to/moss/executable] -l [language] -c [name] [path/to/files]
The moss script contains detailed usage instructions that explain each possible option, but, as shown here, -l and -c do everything that I need.
Specify a language with -l. This option tells MOSS which language the files are in, so it can process them appropriately. Since the exam submissions are written in Java, we specify -l java.
MOSS supports the following languages:
@languages = (“c”, “cc”, “java”, “ml”, “pascal”, “ada”, “lisp”, “scheme”, “haskell”, “fortran”, “ascii”, “vhdl”, “perl”, “matlab”, “python”, “mips”, “prolog”, “spice”, “vb”, “csharp”, “modula2”, “a8086”, “javascript”, “plsql”, “verilog”);
Provide a label with -c. This option informs MOSS that we would like to label our report as such, for our own records.
Terminal output:



(base) me@Briennas-MBP MOSS % ./moss.pl -l java -c "Midterm Exam" ./Midterm_Exam/*.java
Checking files . . .
OK
Uploading ./Midterm_Exam/A.java ...done.
Uploading ./Midterm_Exam/B.java ...done.
Uploading ./Midterm_Exam/C.java ...done.
Uploading ./Midterm_Exam/D.java ...done.
Uploading ./Midterm_Exam/E.java ...done.
Uploading ./Midterm_Exam/F.java ...done.
Uploading ./Midterm_Exam/G.java ...done.
Uploading ./Midterm_Exam/H.java ...done.
Uploading ./Midterm_Exam/I.java ...done.
Uploading ./Midterm_Exam/J.java ...done.
Uploading ./Midterm_Exam/K.java ...done.
Uploading ./Midterm_Exam/L.java ...done.
Query submitted.  Waiting for the server's response.
http://moss.stanford.edu/results/7/8894930687706
Once MOSS finishes and returns the result as a URL, copy and paste it into a browser. The URL is valid for 14 days. After that, you will need to resubmit the query to see the results again.




./moss.pl -l python -c "plag" ./plag/*.py
