clear
clc

count = importdata("counts.txt");
word = fopen("words.txt");
words = textscan(word,'%s');
fclose(word);
Word = words{1,1};


graphCount = count(1:10);
firstWords = Word(1:10);
graphWords = categorical(firstWords);
graphWords = reordercats(graphWords,firstWords);

bar(graphWords,graphCount);
title("Most Frequently Occuring Words in The Hunger Games");
xlabel("Words");
ylabel("Number of Occurences");

figure;
wordTB = table(Word,count);
wordcloud(wordTB, "Word","count");
title("The Hunger Games Wordcloud");

