object Form1: TForm1
  Left = 226
  Top = 174
  Width = 979
  Height = 563
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 971
    Height = 517
    Align = alClient
    Lines.Strings = (
      '')
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 80
    Top = 48
  end
  object ServerSocket1: TServerSocket
    Active = True
    Port = 80
    ServerType = stNonBlocking
    OnClientRead = ServerSocket1ClientRead
    Left = 80
    Top = 76
  end
  object MainMenu1: TMainMenu
    Left = 216
    Top = 184
    object Controle1: TMenuItem
      Caption = 'Controle'
      object AbrirCOMM1: TMenuItem
        Caption = 'Abrir COMM'
        OnClick = AbrirCOMM1Click
      end
    end
  end
end
