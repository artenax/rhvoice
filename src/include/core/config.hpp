/* Copyright (C) 2012  Olga Yakovleva <yakovleva.o.v@gmail.com> */

/* This program is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU Lesser General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or */
/* (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU Lesser General Public License for more details. */

/* You should have received a copy of the GNU Lesser General Public License */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef RHVOICE_CONFIG_HPP
#define RHVOICE_CONFIG_HPP

#include <string>
#include <map>
#include "str.hpp"
#include "property.hpp"

namespace RHVoice
{
  class config
  {
  private:
    typedef std::map<std::string,abstract_property*,str::less> registration_map;
    registration_map registered_settings;

  public:
    void register_setting(abstract_property& setting,const std::string& prefix="")
    {
      registered_settings.insert(registration_map::value_type(prefix.empty()?setting.get_name():(prefix+"."+setting.get_name()),&setting));
    }

    bool set(const std::string& name,const std::string& value);

    void load(const std::string& file_path);
  };
}
#endif 
