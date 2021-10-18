using System;
using System.IO.Ports;
using System.Text;

namespace binaryCalculator
{
    class Program
    {
        static void Main(string[] args)
        {
            // configuracion del puerto
            SerialPort _serialPort = new SerialPort();
            _serialPort.PortName = "COM6";
            _serialPort.BaudRate = 115200;
            _serialPort.DtrEnable = true;
            _serialPort.Open();

            // buffer para recibir los datos
            int bufferTam = 4;
            byte[] buffer = new byte[bufferTam];

            while (true)
            {
                // leer la operacion
                string operacionUsuario = Console.ReadLine();
                
                if (operacionUsuario == "exit")
                {
                    _serialPort.Close();
                    Environment.Exit(0);
                }

                if(operacionUsuario.Length > 0)
                {
                    string[] paraConvertir = operacionUsuario.Split(' ');

                    // convertir al mensaje a enviar
                    Single float1 = Convert.ToSingle(paraConvertir[0]);
                    Single float2 = Convert.ToSingle(paraConvertir[2]);
                    byte[] bytesSigno = Encoding.ASCII.GetBytes(paraConvertir[1]);
                    byte[] bytesFloat1 = BitConverter.GetBytes(float1);
                    byte[] bytesFloat2 = BitConverter.GetBytes(float2);

                    // Console.WriteLine(BitConverter.ToString(bytesFloat1));
                    // Console.WriteLine(BitConverter.ToString(bytesSigno));
                    // Console.WriteLine(BitConverter.ToString(bytesFloat2));

                    // enviar los datos
                    _serialPort.Write(bytesFloat1, 0, 4);
                    _serialPort.Write(bytesSigno, 0, 1);
                    _serialPort.Write(bytesFloat2, 0, 4);

                    while(_serialPort.BytesToRead < bufferTam)
                    { }

                    // respuesta
                    if (_serialPort.BytesToRead >= bufferTam)
                    {
                        Console.SetCursorPosition(operacionUsuario.Length, Console.CursorTop - 1);
                        // guardar lo leido en el buffer
                        _serialPort.Read(buffer, 0, bufferTam);

                        //Console.WriteLine(BitConverter.ToString(buffer));
                        Console.Write(System.BitConverter.ToSingle(buffer, 0));
                    }
                    else
                    {
                        Console.SetCursorPosition(operacionUsuario.Length, Console.CursorTop);
                        Console.Write("SIN RESPUESTA");
                    }

                    Console.WriteLine();
                    Array.Clear(buffer, 0, buffer.Length);
                    // Console.ReadKey();
                }

            }
        
        }
    }
}
