#pragma once

template <typename N/*, typename = std::enable_if_t<std::is_base_of<int,N>::value>*/> N deg2rad(N);
template <typename N> N rad2deg(N angle);