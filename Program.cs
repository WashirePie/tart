﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using CustomExtensions;

namespace Tart
{
    public delegate void FormatFunction();

    class Program
    {
        public static string ReadText;
        public static string ConvertedText;
        public static int WordCount;
        public static AppParams App;

        static void Main(string[] args)
        {
            App = new AppParams(args);

            // Open the file to read from.
            ReadText = File.ReadAllText(App.FilePath);
            ConvertedText = ReadText.CleanText();
            WordCount = ConvertedText.GetWordCount();

            #region Apply Formatting

            // Instantiate delegate
            FormatFunction FormatFunction = null;

            switch (App.Mode)
            {
                case "-stair":  FormatFunction = FormatStair;      break;
                case "-sine":   FormatFunction = FormatSine;       break;
                case "-tan":    FormatFunction = FormatTangential; break;
                case "-blocks": FormatFunction = FormatBlocks;     break;

                default:
                    Console.WriteLine($"Don't know specified mode '{App.Mode}'");
                    App.PlotAppUsage(1);
                    break;
            }

            FormatFunction();

            #endregion

            File.WriteAllText($"{App.FilePath}.tart", ConvertedText, Encoding.UTF8);
        }

        public static void FormatSine()
        {
            for (int i = 0; i < WordCount; i++)
            {
                double x = Convert.ToDouble(i) / App.Params[1];
                int spaces = (int)((Math.Sin(x) + 1d) * Convert.ToDouble(App.Params[0]));
                ConvertedText = ConvertedText.InsertAtWordIndex(i, Environment.NewLine + new string(' ', spaces));
            }
        }

        public static void FormatStair()
        {
            for (int i = 0; i < WordCount; i++)
            {
                int spaces = i % App.Params[0] + App.Params[1];
                ConvertedText = ConvertedText.InsertAtWordIndex(i, Environment.NewLine + new string(' ', spaces));
            }
        }

        public static void FormatTangential()
        {
            for (int i = 0; i < WordCount; i++)
            {
                double x = Convert.ToDouble(i) / App.Params[1];
                int spaces = (int)(Math.Tan(x) + (double)App.Params[0]);
                spaces = spaces > App.ParamUBound ? App.ParamUBound : spaces;
                spaces = spaces < 0 ? 0 : spaces;
                ConvertedText = ConvertedText.InsertAtWordIndex(i, Environment.NewLine + new string(' ', spaces));
            }
        }

        public static void FormatBlocks()
        {
            Random Inset = new Random();

            for (int i = 0; i < WordCount; i+= App.Params[0])
            {
                int spaces = Inset.Next(0, App.Params[1]);
                for (int j = 0; j < App.Params[0]; j++)
                {
                    if (i + j < WordCount)
                    {
                        ConvertedText = ConvertedText.InsertAtWordIndex(i + j, Environment.NewLine + new string(' ', spaces));
                    }
                }
            }
        }
    }

    class AppParams
    {
        public string Mode = "-tan";
        public List<int> Params = new List<int>();
        public int ParamUBound = 200;
        public int ParamLBound = 1;
        public string FilePath = "";

        public AppParams(string[] arguments)
        {
            // 10, 30  for Stair
            // 20, 4   for Sine
            // 20, 30  for Tangential
            // 5, 100 for Blocks
            Params.Add(20);
            Params.Add(30);

            if (arguments.Length < 1) PlotAppUsage(0);

            // The FilePath is always the last argument
            FilePath = arguments[arguments.Length - 1];

            if (arguments.Length > 4) PlotAppUsage(1);
            if (arguments.Length > 1) Mode = arguments[0];
            if (arguments.Length == 3) Params[0] = Int16.Parse(arguments[1]);
            if (arguments.Length == 4) Params[1] = Int16.Parse(arguments[2]);

            // Check if Params are within limits
            Params.ForEach(p =>
            {
                if (p < ParamLBound || p > ParamUBound)
                {
                    Console.WriteLine($"Parameter {p} must be > {ParamLBound} and < {ParamUBound}");
                    PlotAppUsage(1);
                }
            });

            // Check if File exists
            if (!File.Exists(FilePath))
            {
                Console.WriteLine("File does not exist");
                PlotAppUsage(1);
            }
        }

        public void PlotAppUsage(int ExitCode)
        {
            Console.WriteLine($"usage: tart.exe [-mode] [-p1] [-p2] [-file]");
            Console.WriteLine($"");
            Console.WriteLine($" [-mode] specifies the mode of this tool");
            Console.WriteLine($"         nothing (defaults to '-stair') ");
            Console.WriteLine($"         -stair     create a staircase pattern");
            Console.WriteLine($"         -sine      create a sinewave pattern");
            Console.WriteLine($"         -tan       create a tangentual pattern");
            Console.WriteLine($" [-p1] parameter 1, used to adjust stair amount, sine amplitude or tan zero offset");
            Console.WriteLine($"         nothing (default value)");
            Console.WriteLine($"         {ParamLBound} to {ParamUBound}");
            Console.WriteLine($" [-p2] parameter 2, used to adjust stair inset, sine period or tan width");
            Console.WriteLine($"         nothing (default value)");
            Console.WriteLine($"         {ParamLBound} to {ParamUBound}");
            Console.WriteLine($" [-file] specifies the path to the desired text file.");
            Console.ReadLine();
            Environment.Exit(ExitCode);
        }
    }

}