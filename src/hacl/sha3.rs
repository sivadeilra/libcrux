#![allow(dead_code)]

use libcrux_hacl::{
    Hacl_Hash_SHA3_sha3_224, Hacl_Hash_SHA3_sha3_256, Hacl_Hash_SHA3_sha3_384,
    Hacl_Hash_SHA3_sha3_512, Hacl_Hash_SHA3_shake128_hacl, Hacl_Hash_SHA3_shake256_hacl,
};

/// SHA3 224
#[inline(always)]
pub(crate) fn sha224(payload: &[u8]) -> [u8; 28] {
    let mut digest = [0u8; 28];
    unsafe {
        Hacl_Hash_SHA3_sha3_224(
            digest.as_mut_ptr(),
            payload.as_ptr() as _,
            payload.len().try_into().unwrap(),
        );
    }
    digest
}

/// SHA3 256
#[inline(always)]
pub(crate) fn sha256(payload: &[u8]) -> [u8; 32] {
    let mut digest = [0u8; 32];
    unsafe {
        Hacl_Hash_SHA3_sha3_256(
            digest.as_mut_ptr(),
            payload.as_ptr() as _,
            payload.len().try_into().unwrap(),
        );
    }
    digest
}

/// SHA3 384
#[inline(always)]
pub(crate) fn sha384(payload: &[u8]) -> [u8; 48] {
    let mut digest = [0u8; 48];
    unsafe {
        Hacl_Hash_SHA3_sha3_384(
            digest.as_mut_ptr(),
            payload.as_ptr() as _,
            payload.len().try_into().unwrap(),
        );
    }
    digest
}

/// SHA3 512
#[inline(always)]
pub(crate) fn sha512(payload: &[u8]) -> [u8; 64] {
    let mut digest = [0u8; 64];
    unsafe {
        Hacl_Hash_SHA3_sha3_512(
            digest.as_mut_ptr(),
            payload.as_ptr() as _,
            payload.len().try_into().unwrap(),
        );
    }
    digest
}

/// SHAKE 128
#[inline(always)]
pub(crate) fn shake128<const BYTES: usize>(data: &[u8]) -> [u8; BYTES] {
    let mut out = [0u8; BYTES];
    unsafe {
        Hacl_Hash_SHA3_shake128_hacl(
            data.len() as u32,
            data.as_ptr() as _,
            BYTES as u32,
            out.as_mut_ptr(),
        );
    }
    out
}

/// SHAKE 256
///
/// Note that the output length `BYTES` must fit into 32 bit. If it is longer,
/// the output will only return `u32::MAX` bytes.
#[inline(always)]
pub(crate) fn shake256<const BYTES: usize>(data: &[u8]) -> [u8; BYTES] {
    let mut out = [0u8; BYTES];
    unsafe {
        Hacl_Hash_SHA3_shake256_hacl(
            data.len() as u32,
            data.as_ptr() as _,
            BYTES as u32,
            out.as_mut_ptr(),
        );
    }
    out
}

#[cfg(simd256)]
pub mod x4 {
    use libcrux_hacl::{
        Hacl_Hash_SHA3_Simd256_sha3_224, Hacl_Hash_SHA3_Simd256_sha3_256,
        Hacl_Hash_SHA3_Simd256_sha3_384, Hacl_Hash_SHA3_Simd256_sha3_512,
        Hacl_Hash_SHA3_Simd256_shake128, Hacl_Hash_SHA3_Simd256_shake256,
    };

    macro_rules! impl_sha3_vec {
        ($name:ident, $fun:expr, $out_len:literal) => {
            #[inline(always)]
            pub(crate) fn $name(
                payload0: &[u8],
                payload1: &[u8],
                payload2: &[u8],
                payload3: &[u8],
            ) -> (
                [u8; $out_len],
                [u8; $out_len],
                [u8; $out_len],
                [u8; $out_len],
            ) {
                let input_len = payload0.len();
                debug_assert!(
                    input_len == payload1.len()
                        && input_len == payload2.len()
                        && input_len == payload3.len()
                        && input_len <= u32::MAX as usize
                );
                let mut digest0 = [0u8; $out_len];
                let mut digest1 = [0u8; $out_len];
                let mut digest2 = [0u8; $out_len];
                let mut digest3 = [0u8; $out_len];
                unsafe {
                    $fun(
                        input_len as u32,
                        payload0.as_ptr() as _,
                        payload1.as_ptr() as _,
                        payload2.as_ptr() as _,
                        payload3.as_ptr() as _,
                        digest0.as_mut_ptr(),
                        digest1.as_mut_ptr(),
                        digest2.as_mut_ptr(),
                        digest3.as_mut_ptr(),
                    );
                }
                (digest0, digest1, digest2, digest3)
            }
        };
    }

    impl_sha3_vec!(sha224, Hacl_Hash_SHA3_Simd256_sha3_224, 28);
    impl_sha3_vec!(sha256, Hacl_Hash_SHA3_Simd256_sha3_256, 32);
    impl_sha3_vec!(sha384, Hacl_Hash_SHA3_Simd256_sha3_384, 48);
    impl_sha3_vec!(sha512, Hacl_Hash_SHA3_Simd256_sha3_512, 64);

    /// SHAKE 128
    #[inline(always)]
    pub(crate) fn shake128<const BYTES: usize>(
        payload0: &[u8],
        payload1: &[u8],
        payload2: &[u8],
        payload3: &[u8],
    ) -> ([u8; BYTES], [u8; BYTES], [u8; BYTES], [u8; BYTES]) {
        let input_len = payload0.len();
        debug_assert!(
            input_len == payload1.len()
                && input_len == payload2.len()
                && input_len == payload3.len()
                && input_len <= u32::MAX as usize
                && BYTES <= u32::MAX as usize
        );
        let mut digest0 = [0u8; BYTES];
        let mut digest1 = [0u8; BYTES];
        let mut digest2 = [0u8; BYTES];
        let mut digest3 = [0u8; BYTES];
        unsafe {
            Hacl_Hash_SHA3_Simd256_shake128(
                input_len as u32,
                payload0.as_ptr() as _,
                payload1.as_ptr() as _,
                payload2.as_ptr() as _,
                payload3.as_ptr() as _,
                BYTES as u32,
                digest0.as_mut_ptr(),
                digest1.as_mut_ptr(),
                digest2.as_mut_ptr(),
                digest3.as_mut_ptr(),
            );
        }
        (digest0, digest1, digest2, digest3)
    }

    /// SHAKE 256
    ///
    /// Note that the output length `BYTES` must fit into 32 bit. If it is longer,
    /// the output will only return `u32::MAX` bytes.
    #[inline(always)]
    pub(crate) fn shake256<const BYTES: usize>(
        payload0: &[u8],
        payload1: &[u8],
        payload2: &[u8],
        payload3: &[u8],
    ) -> ([u8; BYTES], [u8; BYTES], [u8; BYTES], [u8; BYTES]) {
        let input_len = payload0.len();
        debug_assert!(
            input_len == payload1.len()
                && input_len == payload2.len()
                && input_len == payload3.len()
                && input_len <= u32::MAX as usize
                && BYTES <= u32::MAX as usize
        );
        let mut digest0 = [0u8; BYTES];
        let mut digest1 = [0u8; BYTES];
        let mut digest2 = [0u8; BYTES];
        let mut digest3 = [0u8; BYTES];
        unsafe {
            Hacl_Hash_SHA3_Simd256_shake256(
                input_len as u32,
                payload0.as_ptr() as _,
                payload1.as_ptr() as _,
                payload2.as_ptr() as _,
                payload3.as_ptr() as _,
                BYTES as u32,
                digest0.as_mut_ptr(),
                digest1.as_mut_ptr(),
                digest2.as_mut_ptr(),
                digest3.as_mut_ptr(),
            );
        }
        (digest0, digest1, digest2, digest3)
    }
}
