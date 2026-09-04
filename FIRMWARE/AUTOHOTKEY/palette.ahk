SetColorPaint(hexColor){
    Send, {Alt down}
    Sleep, 200
    Send, {Alt up}
    Sleep, 300
    Send, e
    Sleep, 300
    Send, c
    Sleep, 300
    Send, {Tab 2}
    Sleep, 200
    Send, {End}
    Send, +{Home}
    Sleep, 100
    Send, {Delete}
    Sleep, 1000
    Send, %hexColor%
    Send, {Enter}




}



F13::SetColorPaint("FF0000")
F14::SetColorPaint("F0900E")
F15::SetColorPaint("F0E50E")
F16::SetColorPaint("16AB16")
F18::SetColorPaint("6DF7E9")
F19::SetColorPaint("1921A6")
F20::SetColorPaint("6019A6")
F21::SetColorPaint("DD22E0")
F22::SetColorPaint("E68CA7")
F23::SetColorPaint("422B0D")
F24::SetColorPaint("000000")
KP1::SetColorPaint("FFFFFF")
KP2::SetColorPaint("6E6666")
KP3::SetColorPaint("946519")
KP4::SetColorPaint("B89300")