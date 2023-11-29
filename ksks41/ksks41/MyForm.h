#include <Winsock2.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <thread>
#include <vcclr.h>
#include <msclr/marshal_cppstd.h>
#pragma comment(lib, "ws2_32.lib")

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;


struct Command {
    std::string comanda;
    std::vector<std::string> parametr;
};

bool ValidCommand = false;
int selected = 0;

int orin = 0;

int IntParametrs[8];
int kol = 0;
std::string textp[1];
int kol2 = 0;
int ricyem = 0;
int j = 0;
int IsText = 0;
int count = 1;
int this_time = 0;


namespace ksks41 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Drawing::Drawing2D;

    /// <summary>
    /// Сводка для MyForm
    /// </summary>


    public ref class MyForm : public System::Windows::Forms::Form
    {
    private:
        UdpClient^ udpServer;
    private: System::Windows::Forms::Label^ label1;
           int port = 12345;

    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Label^ label2;

    private: System::Windows::Forms::Label^ label3;
    private: Bitmap^ BittMap;
    public:
        MyForm(void)
        {
            InitializeComponent();
            //
            //TODO: добавьте код конструктора
            //
            udpServer = gcnew UdpClient(port);
            udpServer->BeginReceive(gcnew AsyncCallback(this, &MyForm::ReceiveCallback), nullptr);
            BittMap = gcnew Bitmap(panel1->Width, panel1->Height);
        }
    private:
        void ReceiveCallback(IAsyncResult^ ar)
        {
            IPEndPoint^ endPoint = gcnew IPEndPoint(IPAddress::Any, port);
            array<Byte>^ receiveBytes = udpServer->EndReceive(ar, endPoint);
            String^ receivedMessage = Encoding::ASCII->GetString(receiveBytes);

            // Обработка полученного сообщения
            // Ваш код для обработки сообщения
            this->Invoke(gcnew Action<String^>(this, &MyForm::parsi), receivedMessage);
            // Продолжаем прослушивать порт
            udpServer->BeginReceive(gcnew AsyncCallback(this, &MyForm::ReceiveCallback), nullptr);
        }

    protected:
        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->Location = System::Drawing::Point(12, 49);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(252, 41);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Пустая строка\r\n";
            // 
            // panel1
            // 
            this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel1->Location = System::Drawing::Point(12, 160);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(905, 487);
            this->panel1->TabIndex = 2;
            this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(971, 160);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(324, 487);
            this->textBox1->TabIndex = 3;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label2->Location = System::Drawing::Point(998, 49);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(284, 41);
            this->label2->TabIndex = 4;
            this->label2->Text = L"История команд";


            this->label3->AutoSize = true;
            this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label3->Location = System::Drawing::Point(450, 49);
            this->label3->Name = L"label1";
            this->label3->Size = System::Drawing::Size(252, 41);
            this->label3->TabIndex = 0;
            this->label3->Text = L"Время\r\n";

            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1307, 659);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->label1);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    private:
        System::Windows::Forms::Timer^ timer;

        void DrawRoundedRectangle(Graphics^ g, Pen^ pen, int x, int y, int width, int height, int radius)
        {
            GraphicsPath^ path = gcnew GraphicsPath();

            System::Drawing::Rectangle rect = System::Drawing::Rectangle(x, y, width, height);

            int diameter = 2 * radius;
            System::Drawing::Rectangle arc = System::Drawing::Rectangle(rect.Location, System::Drawing::Size(diameter, diameter));

            path->AddArc(arc, 180, 90);
            arc.X = rect.Right - diameter;
            path->AddArc(arc, 270, 90);
            arc.Y = rect.Bottom - diameter;
            path->AddArc(arc, 0, 90);
            arc.X = rect.Left;
            path->AddArc(arc, 90, 90);

            path->CloseFigure();


            g->DrawPath(pen, path);

            delete path;
        }

        void FillRoundedRectangle(Graphics^ g, int x, int y, int width, int height, int radius, Color fillColor)
        {
            System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();

            System::Drawing::Rectangle rect = System::Drawing::Rectangle(x, y, width, height);

            int diameter = 2 * radius;
            System::Drawing::Rectangle arc = System::Drawing::Rectangle(rect.Location, System::Drawing::Size(diameter, diameter));

            path->AddArc(arc, 180, 90);
            arc.X = rect.Right - diameter;
            path->AddArc(arc, 270, 90);
            arc.Y = rect.Bottom - diameter;
            path->AddArc(arc, 0, 90);
            arc.X = rect.Left;
            path->AddArc(arc, 90, 90);

            path->CloseFigure();

            SolidBrush^ fillBrush = gcnew SolidBrush(fillColor);
            g->FillPath(fillBrush, path);

            delete path;
            delete fillBrush;
        }

        void Draw_Text(Graphics^ g, String^ text, Color textColor, int x, int y, int fonte, int len)
        {
            System::Drawing::Font^ font;
            switch (fonte)
            {
            case 1:
                font = gcnew System::Drawing::Font("Arial", len);
                break;
            case 2:
                font = gcnew System::Drawing::Font("Times New Roman", len);
                break;
            case 3:
                font = gcnew System::Drawing::Font("Comic Sans MS", len);
                break;
            default:
                ValidCommand = true;
                break;
            }
            System::Drawing::Brush^ brush = gcnew SolidBrush(textColor);
            Matrix^ rotationMatrix = gcnew Matrix();
            rotationMatrix->RotateAt(orin, Point(x, y));

            g->Transform = rotationMatrix;


            g->DrawString(text, font, brush, x, y);
        }

        void draw_time2()
        {
            System::Threading::Thread::Sleep(1000);
        }


        void Draw_Time(Graphics^ g, String^ text, Color textColor, int x, int y, int fonte, int len, int timee)
        {
            System::Drawing::Font^ font;
            switch (fonte)
            {
            case 1:
                font = gcnew System::Drawing::Font("Arial", len);
                break;
            case 2:
                font = gcnew System::Drawing::Font("Times New Roman", len);
                break;
            case 3:
                font = gcnew System::Drawing::Font("Comic Sans MS", len);
                break;
            default:
                ValidCommand = true;
                break;
            }
            System::Drawing::Brush^ brush = gcnew SolidBrush(textColor);
            String^ time_s = timee.ToString();
            g->DrawString("Time: " + time_s, font, brush, x, y);
        }

        Color MyCol()
        {
            if (1 == IntParametrs[j])
            {
                return Color::Blue;
            }
            else if (2 == IntParametrs[j])
            {
                return Color::Red;
            }
            else if (3 == IntParametrs[j])
            {
                return Color::Green;
            }
            else if (4 == IntParametrs[j])
            {
                return Color::Cyan;
            }
            else if (5 == IntParametrs[j])
            {
                return Color::White;
            }
            else if (6 == IntParametrs[j])
            {
                return Color::Gray;
            }
            else if (7 == IntParametrs[j])
            {
                return Color::Yellow;
            }
            else  if (8 == IntParametrs[j])
            {
                return Color::Brown;
            }
            else  if (9 == IntParametrs[j])
            {
                return Color::Black;
            }
            else if (10 == IntParametrs[j])
            {
                return Color::LightGray;
            }
            else  if (11 == IntParametrs[j])
            {
                return Color::DarkGray;
            }
            else if (12 == IntParametrs[j])
            {
                return Color::Orange;
            }
            else if (13 == IntParametrs[j])
            {
                return Color::Pink;
            }
            else if (14 == IntParametrs[j])
            {
                return Color::Purple;
            }
            else {
                return Color::White;
                ValidCommand = true;
            }
        }

        void drawImage(Graphics^ g, int x0, int y0, int w, int h, array<Color>^ imageData)
        {
            for (int x = 0; x < w; x++)
            {
                for (int y = 0; y < h; y++)
                {
                    Color pixelColor = imageData[x + y * w];
                    SolidBrush^ brush = gcnew SolidBrush(pixelColor);
                    g->FillRectangle(brush, x0 + x, y0 + y, 1, 1);
                }
            }
        }

        void drawLetterA(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 20, y + 0);
            g->DrawLine(pen, x + 20, y + 0, x + 40, y + 100);
            g->DrawLine(pen, x + 5, y + 50, x + 40, y + 50);
        }
        void drawLetterB(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 0, y + 0, x + 40, y + 25);
            g->DrawLine(pen, x + 40, y + 25, x + 0, y + 50);

            g->DrawLine(pen, x + 0, y + 100, x + 40, y + 75);
            g->DrawLine(pen, x + 40, y + 75, x + 0, y + 50);

        }

        void drawLetterC(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 0, y + 100);
            g->DrawLine(pen, x + 40, y + 0, x + 0, y + 0);
        }
        void drawLetterD(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 15, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 85, x + 0, y + 100);
            g->DrawLine(pen, x + 40, y + 85, x + 40, y + 15);
        }
        void drawLetterE(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 0, y + 100);
            g->DrawLine(pen, x + 30, y + 50, x + 0, y + 50);
            g->DrawLine(pen, x + 40, y + 0, x + 0, y + 0);
        }
        void drawLetterF(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 50, x + 0, y + 50);
            g->DrawLine(pen, x + 40, y + 0, x + 0, y + 0);
        }
        void drawLetterG(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 0, y + 100);
            g->DrawLine(pen, x + 40, y + 100, x + 40, y + 55);
            g->DrawLine(pen, x + 20, y + 55, x + 40, y + 55);
            g->DrawLine(pen, x + 40, y + 0, x + 0, y + 0);
        }
        void drawLetterH(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 40, y + 0);
            g->DrawLine(pen, x + 40, y + 50, x + 0, y + 50);
        }
        void drawLetterI(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
        }
        void drawLetterJ(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x + 40, y + 100, x + 40, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 0, y + 100);
        }
        void drawLetterK(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 0, y + 50, x + 40, y + 100);
            g->DrawLine(pen, x + 0, y + 50, x + 40, y + 0);
        }
        void drawLetterL(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x + 0, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 0, y + 100, x + 40, y + 100);
        }
        void drawLetterM(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 40, y + 0);

            g->DrawLine(pen, x + 20, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 20, y + 100, x + 40, y + 0);
        }
        void drawLetterN(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 40, y + 0);

            g->DrawLine(pen, x + 40, y + 100, x + 0, y + 0);
        }
        void drawLetterO(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 40, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 0, y + 100);
            g->DrawLine(pen, x + 40, y + 0, x + 0, y + 0);
        }
        void drawLetterP(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 0, y + 0, x + 40, y + 25);
            g->DrawLine(pen, x + 40, y + 25, x + 0, y + 50);
        }
        void drawLetterQ(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 80, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 40, y + 0);
            g->DrawLine(pen, x + 40, y + 80, x + 0, y + 80);
            g->DrawLine(pen, x + 40, y + 0, x + 0, y + 0);
        }
        void drawLetterR(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 0, y + 0, x + 40, y + 25);
            g->DrawLine(pen, x + 40, y + 25, x + 0, y + 50);
            g->DrawLine(pen, x + 0, y + 50, x + 40, y + 100);
        }
        void drawLetterS(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x + 40, y + 100, x + 0, y + 100);
            g->DrawLine(pen, x + 40, y + 100, x + 40, y + 50);
            g->DrawLine(pen, x + 40, y + 50, x + 0, y + 50);
            g->DrawLine(pen, x + 0, y + 50, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 0, x + 0, y + 0);
        }
        void drawLetterT(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x + 20, y + 100, x + 20, y + 0);
            g->DrawLine(pen, x + 0, y + 0, x + 40, y + 0);
        }
        void drawLetterU(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 40, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 0, y + 100);
        }
        void drawLetterV(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 0, x + 20, y + 100);
            g->DrawLine(pen, x + 20, y + 100, x + 40, y + 0);
        }
        void drawLetterW(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 0, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 40, y + 0);

            g->DrawLine(pen, x + 20, y + 0, x + 0, y + 100);
            g->DrawLine(pen, x + 20, y + 0, x + 40, y + 100);
        }
        void drawLetterX(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 100, x + 40, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 0, y + 0);
        }
        void drawLetterY(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x + 20, y + 50, x + 20, y + 100);
            g->DrawLine(pen, x + 20, y + 50, x + 0, y + 0);
            g->DrawLine(pen, x + 20, y + 50, x + 40, y + 0);
        }
        void drawLetterZ(int x, int y, Graphics^ g, Pen^ pen)
        {
            g->DrawLine(pen, x, y + 0, x + 40, y + 0);
            g->DrawLine(pen, x + 40, y + 100, x + 0, y + 100);
            g->DrawLine(pen, x + 40, y + 0, x + 0, y + 100);
        }

        void RunTextOnPanel(Graphics^ g, String^ text, Color textColor, int x, int y, int fonte, int len)
        {
            System::Drawing::Font^ font;
            switch (fonte)
            {
            case 1:
                font = gcnew System::Drawing::Font("Arial", len);
                break;
            case 2:
                font = gcnew System::Drawing::Font("Times New Roman", len);
                break;
            case 3:
                font = gcnew System::Drawing::Font("Comic Sans MS", len);
                break;
            default:
                ValidCommand = true;
                break;
            }
            System::Drawing::Brush^ brush = gcnew SolidBrush(textColor);

            g->Clear(panel1->BackColor); // Очищаем панель

            // Рассчитываем новые координаты для отображения текста
            IntParametrs[7] = x + 1;
            std::cout << IntParametrs[7] << "\t";

            // Рисуем текст на панели
            g->DrawString(text, font, brush, IntParametrs[7], y);


        }


        void parsi(String^ strings_mes)
        {
            kol = 0;
            kol2 = 0;
            label1->Text = strings_mes;

            if (ValidCommand == false)
            {
                std::string string_mes = msclr::interop::marshal_as<std::string>(strings_mes);
                check_command(string_mes);


                String^ stringValue = count.ToString();
                count++;
                if (count % 39 == 0)
                {
                    textBox1->Text = "";
                }
                textBox1->Text += (stringValue + ". " + strings_mes + "\n");
                Color colorss = MyCol();

                Graphics^ g = Graphics::FromImage(BittMap);
                Pen^ pen = gcnew Pen(colorss, 2);
                SolidBrush^ brush = gcnew SolidBrush(colorss);

                if (ricyem == 1)
                {
                    BittMap = gcnew Bitmap(panel1->Width, panel1->Height);
                    panel1->BackColor = colorss;
                    panel1->Invalidate();
                }

                if (ricyem == 2) {

                    g->DrawLine(pen, IntParametrs[0], IntParametrs[1], IntParametrs[0] + 1, IntParametrs[1] + 1);

                }
                if (ricyem == 3) {

                    g->DrawLine(pen, IntParametrs[0], IntParametrs[1], IntParametrs[2], IntParametrs[3]);
                }
                if (ricyem == 4) {

                    g->DrawRectangle(pen, IntParametrs[0], IntParametrs[1], IntParametrs[2], IntParametrs[3]);
                }
                if (ricyem == 5) {

                    g->FillRectangle(brush, IntParametrs[0], IntParametrs[1], IntParametrs[2], IntParametrs[3]);
                }
                if (ricyem == 6) {

                    g->DrawEllipse(pen, IntParametrs[0], IntParametrs[1], IntParametrs[2], IntParametrs[3]);
                }
                if (ricyem == 7) {

                    g->FillEllipse(brush, IntParametrs[0], IntParametrs[1], IntParametrs[2], IntParametrs[3]);
                }
                if (ricyem == 8)
                {

                    g->DrawEllipse(pen, IntParametrs[0], IntParametrs[1], IntParametrs[2], IntParametrs[2]);
                }
                if (ricyem == 9)
                {

                    g->FillEllipse(brush, IntParametrs[0], IntParametrs[1], IntParametrs[2], IntParametrs[2]);
                }
                if (ricyem == 10)
                {
                    DrawRoundedRectangle(g, pen, IntParametrs[0], IntParametrs[1], IntParametrs[2], IntParametrs[3], IntParametrs[4]);
                }
                if (ricyem == 11)
                {
                    FillRoundedRectangle(g, IntParametrs[0], IntParametrs[1], IntParametrs[2], IntParametrs[3], IntParametrs[4], colorss);
                }
                if (ricyem == 12)
                {
                    String^ textToDraw = msclr::interop::marshal_as<String^>(textp[0]);
                    Draw_Text(g, textToDraw, colorss, IntParametrs[0], IntParametrs[1], IntParametrs[3], IntParametrs[4]);
                }
                if (ricyem == 13)
                {
                    array<Color>^ imageData = gcnew array<Color>(IntParametrs[2] * IntParametrs[3]);

                    for (int i = 0; i < imageData->Length; i++)
                    {
                        imageData[i] = colorss;
                    }


                    drawImage(g, IntParametrs[0], IntParametrs[1], IntParametrs[2], IntParametrs[3], imageData);
                }

                if (ricyem == 14)
                {
                    this_time = IntParametrs[5];
                    while (IntParametrs[5] != -1)
                    {
                        if (this_time + 1 == IntParametrs[5] + 1)
                        {
                            Draw_Time(g, "Time :", colorss, IntParametrs[0], IntParametrs[1], IntParametrs[3], IntParametrs[4], IntParametrs[5]);
                        }
                        else
                        {
                            draw_time2();
                            count++;
                            String^ stringValue4 = count.ToString();
                            String^ stringValue5 = (IntParametrs[5] - 2).ToString();
                            textBox1->Text += (stringValue4 + ". |" + stringValue4 + " Seconds|  " + "\n");
                        }
                        IntParametrs[5] -= 1;
                    }
                }
                if (ricyem == 18)
                {
                    Screen^ MonikScreen = Screen::PrimaryScreen;
                    int screenWidth = MonikScreen->Bounds.Width;
                    String^ textToDraw = "Width: " + screenWidth;
                    Draw_Text(g, textToDraw, Color::Black, 100, 50, 1, 24);
                }
                if (ricyem == 19)
                {
                    Screen^ MonikScreen = Screen::PrimaryScreen;
                    int screenHeight = MonikScreen->Bounds.Height;
                    String^ textToDraw = "Height: " + screenHeight;
                    Draw_Text(g, textToDraw, Color::Black, 100, 300, 1, 24);
                }

                if (ricyem == 16)
                {
                    orin = IntParametrs[0];
                }
                if (ricyem == 15)
                {
                    std::string wordd = "Lines_Text";
                    //std::string wordd = textp[0];
                    int x = IntParametrs[0], y = IntParametrs[1];
                    for (char letter : wordd) {
                        if (letter == 'A' || letter == 'a') {
                            std::cout << letter;
                            drawLetterA(x, y, g, pen);
                        }
                        else if (letter == 'B' || letter == 'b') {
                            drawLetterB(x, y, g, pen);
                        }
                        else if (letter == 'C' || letter == 'c') {
                            drawLetterC(x, y, g, pen);
                        }
                        else if (letter == 'D' || letter == 'd') {
                            drawLetterD(x, y, g, pen);
                        }
                        else if (letter == 'E' || letter == 'e') {
                            drawLetterE(x, y, g, pen);
                        }
                        else if (letter == 'F' || letter == 'f') {
                            drawLetterF(x, y, g, pen);
                        }
                        else if (letter == 'G' || letter == 'g') {
                            drawLetterG(x, y, g, pen);
                        }
                        else if (letter == 'H' || letter == 'h') {
                            drawLetterH(x, y, g, pen);
                        }
                        else if (letter == 'I' || letter == 'i') {
                            drawLetterI(x, y, g, pen);
                        }
                        else if (letter == 'J' || letter == 'j') {
                            drawLetterJ(x, y, g, pen);
                        }
                        else if (letter == 'K' || letter == 'k') {
                            drawLetterK(x, y, g, pen);
                        }
                        else if (letter == 'L' || letter == 'l') {
                            drawLetterL(x, y, g, pen);
                        }
                        else if (letter == 'M' || letter == 'm') {
                            drawLetterM(x, y, g, pen);
                        }
                        else if (letter == 'N' || letter == 'n') {
                            drawLetterN(x, y, g, pen);
                        }
                        else if (letter == 'O' || letter == 'o') {
                            drawLetterO(x, y, g, pen);
                        }
                        else if (letter == 'P' || letter == 'p') {
                            drawLetterP(x, y, g, pen);
                        }
                        else if (letter == 'Q' || letter == 'q') {
                            drawLetterQ(x, y, g, pen);
                        }
                        else if (letter == 'R' || letter == 'r') {
                            drawLetterR(x, y, g, pen);
                        }
                        else if (letter == 'S' || letter == 's') {
                            drawLetterS(x, y, g, pen);
                        }
                        else if (letter == 'T' || letter == 't') {
                            drawLetterT(x, y, g, pen);
                        }
                        else if (letter == 'U' || letter == 'u') {
                            drawLetterU(x, y, g, pen);
                        }
                        else if (letter == 'V' || letter == 'v') {
                            drawLetterV(x, y, g, pen);
                        }
                        else if (letter == 'W' || letter == 'w') {
                            drawLetterW(x, y, g, pen);
                        }
                        else if (letter == 'X' || letter == 'x') {
                            drawLetterX(x, y, g, pen);
                        }
                        else if (letter == 'Y' || letter == 'y') {
                            drawLetterY(x, y, g, pen);
                        }
                        else if (letter == 'Z' || letter == 'z') {
                            drawLetterZ(x, y, g, pen);
                        }
                        x += 60;
                    }
                }

                if (ricyem == 20)
                {
                    std::cout << "One";
                    timer = gcnew System::Windows::Forms::Timer();
                    timer->Interval = 10;
                    timer->Tick += gcnew EventHandler(this, &MyForm::OnTime);
                    timer->Start();
                }


                delete g;
                delete pen;
                delete brush;

                panel1->Invalidate();
                ricyem = 0;
            }
            else {
                label1->Text = "Неверная команда";
                String^ stringValue = count.ToString();
                count++;
                if (count % 39 == 0)
                {
                    textBox1->Text = "";
                }
                textBox1->Text += (stringValue + ". Неверная команда\n");
            }
        }

        void timeri()
        {
            System::Timers::Timer^ time_win = gcnew System::Timers::Timer(1000);

            time_win->Elapsed += gcnew System::Timers::ElapsedEventHandler(this, &MyForm::elaps_time);

            time_win->Start();
        }

        void elaps_time(System::Object^ sender, System::Timers::ElapsedEventArgs^ e)
        {
            DateTime this_time = DateTime::Now;

            this->Invoke(gcnew Action<String^>(this, &MyForm::UpdateLabel), this_time.ToString("HH:mm:ss"));
        }

        void UpdateLabel(String^ text)
        {
            label3->Text = text;
        }

        void OnTime(Object^ sender, EventArgs^ e) {
            Graphics^ g = panel1->CreateGraphics();
            Color colorss = MyCol();
            String^ textToDraw = msclr::interop::marshal_as<String^>(textp[0]);
            RunTextOnPanel(g, textToDraw, colorss, IntParametrs[7], IntParametrs[1], IntParametrs[3], IntParametrs[4]);
        }

        Command check_command(const std::string& commandStr) {
            Command command;

            int IntData;
            selected = 0;
            int i = 0;

            std::istringstream get_mes_word(commandStr);
            std::string MyWord;
            get_mes_word >> command.comanda;


            while (get_mes_word >> MyWord) {
                if (MyWord == ":")
                {
                    break;
                }
                command.comanda += " " + MyWord;
            }

            if (command.comanda == "clear display") {
                j = 0;
                ricyem = 1;
                selected = 1;
            }
            if (command.comanda == "draw pixel") {
                j = 2;
                ricyem = 2;
                selected = 10;
            }
            if (command.comanda == "draw line") {
                j = 4;
                ricyem = 3;
                selected = 20;
            }
            if (command.comanda == "draw rectangle")
            {
                j = 4;
                ricyem = 4;
                selected = 30;
            }
            if (command.comanda == "fill rectangle") {
                j = 4;
                ricyem = 5;
                selected = 40;
            }
            if (command.comanda == "draw ellipse") {
                j = 4;
                ricyem = 6;
                selected = 50;
            }
            if (command.comanda == "fill ellipse")
            {
                j = 4;
                ricyem = 7;
                selected = 60;
            }
            if (command.comanda == "draw circle")
            {
                j = 3;
                ricyem = 8;
                selected = 70;
            }
            if (command.comanda == "fill circle")
            {
                j = 3;
                ricyem = 9;
                selected = 80;
            }
            if (command.comanda == "draw rounded rectangle")
            {
                j = 5;
                ricyem = 10;
                selected = 90;
            }
            if (command.comanda == "fill rounded rectangle")
            {
                j = 5;
                ricyem = 11;
                selected = 100;
            }
            if (command.comanda == "draw text")
            {
                IsText = 1;
                j = 2;
                ricyem = 12;
                selected = 110;
            }
            if (command.comanda == "draw image")
            {
                j = 4;
                ricyem = 13;
                selected = 120;
            }
            if (command.comanda == "draw time")
            {
                j = 3;
                ricyem = 14;
                selected = 130;
            }
            else if (command.comanda == "show timer")
            {
                timeri();
            }
            if (command.comanda == "draw letter")
            {
                j = 2;
                ricyem = 15;
                selected = 140;
            }
            if (command.comanda == "set orientation")
            {
                ricyem = 16;
            }
            if (command.comanda == "get width")
            {
                ricyem = 18;
            }
            if (command.comanda == "get height")
            {
                ricyem = 19;
            }
            if (command.comanda == "move string")
            {
                IsText = 1;
                j = 2;
                ricyem = 20;
                selected = 110;
                IntParametrs[7] = 0;


                std::cout << "One";
            }


            if (selected == 0) {
                ValidCommand = true;
                return command;
            }


            if (!ValidCommand)
            {
                while (get_mes_word >> MyWord) {
                    command.parametr.push_back(MyWord);
                    try {
                        IntData = std::stoi(MyWord);
                    }
                    catch (const std::invalid_argument& e) {
                        if (IsText != 1)
                        {
                            ValidCommand = true;
                            return command;
                        }
                        else {
                            textp[0] = MyWord;
                        }
                    }
                    IntParametrs[i] = IntData;
                    i++;
                }
                ValidCommand = false;
                IsText = 0;
                return command;

            }
            else {
                return command;
            }
        }


        void mes_get(String^ message) {

        }
#pragma endregion
    private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        e->Graphics->DrawImage(BittMap, 0, 0);
    }
    };
}
