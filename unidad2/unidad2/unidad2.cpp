using System;

public class Eye
{
    public string Color;
}

public class Husky
{
    public string Name;
    public Eye RightEye;
    public Eye LeftEye;

    public Husky CopyHusky()
    {
        var newDog = new Husky{ Name = Name, LeftEye = LeftEye, RightEye = RightEye };
        return newDog;
    }

    public string ToStringDog()
    {
        return String.Format("{0} has a {1} color on his right eye, and a {2} color on his left eye.", Name, RightEye.Color, LeftEye.Color);
    }
}

static class MainClass
{
    public static void Main()
    {
        var pepe = new Husky{ Name = "Pepe", LeftEye = new Eye(), RightEye = new Eye() };
        pepe.LeftEye.Color = pepe.RightEye.Color = "blue";

        var tom = pepe.CopyHusky();
        tom.Name = "Tom";
        tom.LeftEye.Color = tom.RightEye.Color = "brown";


        Console.WriteLine(pepe.ToStringDog());
        Console.WriteLine(tom.ToStringDog());
        Console.ReadKey();

    }
}