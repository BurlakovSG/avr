﻿using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;


namespace objdump.Instructions {

    // BST - Bit Store from Bit in Register to T Flag in SREG.
    // 1111 101d dddd 0bbb
    public class bst: IInstruction {

        public OpInfo info;
        public OpInfo OpInfo { get { return info; } }

        public bst() { info = new OpInfo( "BST", "Bit Store from Bit in Register to T Flag in SREG",
            new Regex( @"1111101\d{5}0\d{3}", RegexOptions.Compiled ) ); }

        public string Disassemble( List< Record > list, ref int counter ) {

            string op;

            var item = list[ counter ];

            try {

                // Преобразуем в двоичное представление.
                var code = Convert.ToString( item.OpCode, 2 ).PadLeft( 16, '0' );

                // Узнаём параметры инструкции.
                // 0123 4567 8901 2345
                // 1111 101d dddd 0bbb
                var Rd = Convert.ToByte( code.Substring( 7, 5 ), 2 );
                var b = Convert.ToByte( code.Substring( 13, 3 ), 2 );

                // Формируем ассемблерный вид команды.

                // Название инструкции.
                op = info.Name.PadRight( Program.ArgumentsPad, ' ' );

                // Параметры.
                op += String.Format( "R{0}, {1}", Rd, b ).PadRight( Program.CommentsPad, ' ' );

                // Описание.
                op += info.Description;

            } catch( Exception ex ) {

                // Отладочное сообщение в случае ошибки.
                op = String.Format( "line: {0}, addr: ${1:X4}, opcode: ${2:X4} - {3}",
                    item.LineNumber, item.Address, item.OpCode, ex.Message );

                throw new Exception( op );
            }

            return op;
        }

    }

}
