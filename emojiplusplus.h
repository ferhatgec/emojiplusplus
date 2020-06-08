/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef EMOJI_PLUS_PLUS_H
#define EMOJI_PLUS_PLUS_H

#include <map>

namespace emojiplusplus {

    static std::map<std::string, std::string> EMOJIS = {
        {":admission_tickets:" , "\U0001F39F"},
        {":aerial_tramway:" , "\U0001F6A1"},
        {":airplane:" , "\U00002708"},
        {":airplane_arriving:" , "\U0001F6EC"},
        {":airplane_departure:" , "\U0001F6EB"},
        {":alarm_clock:" , "\U000023F0"},
        {":alembic:" , "\U00002697"},
        {":space_invader:" , "\U0001F47E"},
        {":ambulance:" , "\U0001F691"},
        {":football:" , "\U0001F3C8"},
        {":smile:" , "\U0001F604"},
        {":zipper__mouth_face:" , "\U0001F910"}
    };  

    std::string EmojiString(std::string s) {
        int index = -1;
        int sLen = s.size();
        for (int i = 0; i < sLen; i++) {
            if (s[i] == *L":") {
                if (index == -1) {
                    index = i;
                }
                else {
                    if (i - index==1) {
                        index = i;
                        continue;
                    }
                    std::map<std::string, std::string>::iterator it;
                    it = EMOJIS.find(s.substr(index, i - index + 1));
                    if (it == EMOJIS.end()) {
                        index = i;
                        continue;
                    }
                    std::string emo = it->second;
                    s.replace(index, i - index + 1 , emo);
                    int goBack = i - index + 1 - emo.size();
                    sLen -= goBack;
                    i -= goBack;
                    index = -1;
                }
            }
        }
        return s;
    }
}

#endif // EMOJI_PLUS_PLUS_H
