using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace CustomExtensions
{
    public static class StringExtention
    {
        public static int GetWordCount(this string sourceText)
        {
            string reNotWhitespace = @"\S+";
            MatchCollection matches = Regex.Matches(sourceText, reNotWhitespace);
            return matches.Count;
        }

        public static string InsertAtWordIndex(this string sourceText, int wordIndex, string textToInsert)
        {
            string reNotWhitespace = @"\S+";
            MatchCollection matches = Regex.Matches(sourceText, reNotWhitespace);

            int index = matches[wordIndex].Index + matches[wordIndex].Length;

            return sourceText.Insert(index, textToInsert);
        }

        public static string CleanText(this string sourceText)
        {
            string sanitizedText = sourceText;

            /* Source: https://stackoverflow.com/questions/36454069/how-to-remove-c-style-comments-from-code */
            string reComments = @"(?:\/\/(?:\\\n|[^\n])*\n)|(?:\/\*[\s\S]*?\*\/)|" +
                                 "((?:R\"([^(\\\\s]{ 0,16})\\([^)]*\\)\\2\")|" +
                                 "(?:@\"[^\"]*?\")| (?: \"(?:\\?\\?'|\\\\|\\\" |\\\\n |[^\"])*?\")|" +
                                @"(?:'(?:\\\\|\\'|\\\n|[^'])*?'))";
            string reSpaces =   @"(\s+)";

            sanitizedText = Regex.Replace(sanitizedText, reComments, "");
            sanitizedText = Regex.Replace(sanitizedText, reSpaces, " ");
            return sanitizedText;
        }
    }
}