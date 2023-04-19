#pragma once

template <typename N/*, typename = std::enable_if_t<std::is_base_of<int,N>::value>*/> N deg2rad(N);
template <typename N/*, static_assert(std::is_same<N, double>::value || std::is_same<N, float>::value)*/
> N rad2deg(N angle);